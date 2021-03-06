#include "bump_allocator.h"

// TODO: Add thread safety to the allocator.

BumpAllocator::BumpAllocator() : bytesAllocated(0), bytesAllocatedWithoutHeaders(0), memAddr(null), top(null) {}

Optional<MemBlock*> BumpAllocator::AllocMemoryBlock(mem_index _size)
{
    Optional<void*> bumpAllocOpt = PltBumpAlloc(_size + MEM_BLOCK_HEADER_SIZE);
    if (bumpAllocOpt.err != null) {
        auto ret = Optional<MemBlock*>((MemBlock*)bumpAllocOpt.val, "Allocation failed, probably OOM.");
        return ret;
    }
    this->memAddr = bumpAllocOpt.val;

    MemBlock *block = (MemBlock *)(this->memAddr);
    byte* startOfPayload = ((byte*)this->memAddr) + MEM_BLOCK_HEADER_SIZE;
    block->payload = startOfPayload;

    // advance the memory address to the end of the allocated block:
    this->memAddr = (void*)(startOfPayload + _size);
    // calculate allocated memory:
    this->bytesAllocated += _size + MEM_BLOCK_HEADER_SIZE;
    this->bytesAllocatedWithoutHeaders += _size;

    auto ret = Optional<MemBlock*>(block, null);
    return ret;
}

Optional<void*> BumpAllocator::Allocate(mem_index _size)
{
    _size = AlignToMachineWord(_size);
    if (_size == 0) {
        auto ret =  Optional<void*>(null, "trying to allocate 0 bytes");
        return ret;
    }
    Optional<MemBlock*> allocBlockOpt = AllocMemoryBlock(_size);
    if (allocBlockOpt.err != null) {
        return Optional<void*>(null, allocBlockOpt.err);
    }
    MemBlock* block = allocBlockOpt.val;
    block->size = _size;
    block->used = true;

    // NOTE: next is used more like a prev for BumpAllocators:
    block->next = this->top;
    this->top = block;
    auto ret =  Optional<void*>(block->payload, null);
    return ret;
}

Optional<bool8> BumpAllocator::DeallocateTopBlock()
{
    if (this->top != null) {
        mem_index blockDataSize = this->top->size;
        mem_index blockSize = blockDataSize + MEM_BLOCK_HEADER_SIZE;
        this->top->used = false;
        this->top = this->top->next;
        auto bumpDeallocOpt = PltBumpDeallocate(blockSize);
        if (bumpDeallocOpt.err != null) {
            auto ret = Optional<bool8>(false, bumpDeallocOpt.err);
            return ret;
        }
        // Decrement the memory address to point to the end of the previous memory block:
        this->memAddr = (void*)bumpDeallocOpt.val;
        this->bytesAllocated -= blockSize;
        this->bytesAllocatedWithoutHeaders -= blockDataSize;

        auto ret = Optional<bool8>(true, null);
        return ret;
    }

    auto ret = Optional<bool8>(false, "nothing to deallocate");
    return ret;
}

Optional<bool8> BumpAllocator::Clear()
{
    auto bumpDeallocOpt = PltBumpDeallocate(this->bytesAllocated);
    if (bumpDeallocOpt.err != null) {
        auto ret = Optional<bool8>(false, bumpDeallocOpt.err);
        return ret;
    }

    this->memAddr = (void*)bumpDeallocOpt.val;
    this->bytesAllocatedWithoutHeaders = 0;
    this->bytesAllocated = 0;
    auto ret = Optional<bool8>(true, null);
    return ret;
}