#include "bump_allocator.h"

// TODO: Add thread safety to the allocator.

BumpAllocator::BumpAllocator() : memAddr(null), top(null) {}

MemBlock* BumpAllocator::AllocMemoryBlock(mem_index _size)
{
    this->memAddr = PltBumpAlloc(_size + MEM_BLOCK_HEADER_SIZE);
    if (this->memAddr < 0) {
        // Allocation failed, probably OOM.
        return (MemBlock*)this->memAddr;
    }
    MemBlock *block = (MemBlock *)(this->memAddr);
    byte* startOfPayload = (byte*)this->memAddr + MEM_BLOCK_HEADER_SIZE;
    block->payload = startOfPayload;

    // advance the memory address to the end of the allocated block:
    this->memAddr = (void*)(startOfPayload + _size);
    return block;
}

void* BumpAllocator::Allocate(mem_index _size)
{
    _size = AlignToMachineWord(_size);
    MemBlock *block = AllocMemoryBlock(_size);
    block->size = _size;
    block->used = true;

    // NOTE: next is used more like a prev for BumpAllocators:
    block->next = this->top;
    this->top = block;
    return block->payload;
}

i32 BumpAllocator::DeallocateTopBlock()
{
    i32 err = 0;
    if (this->top != null) {
        mem_index blockSize = this->top->size + MEM_BLOCK_HEADER_SIZE;
        this->top->used = false;
        this->top = this->top->next;
        err = PltBumpDeallocate(blockSize);
        if (err == 0) {
            // Decrement the memory address to point to the end of the previous memory block:
            this->memAddr = (void*)((byte*)this->memAddr - blockSize);
        }
    } else {
        err = -1;
    }

    return err;
}