#ifndef BUMP_ALLOCATOR_H
#define BUMP_ALLOCATOR_H 1

#include "../types.h"
#include "../debug.h"
#include "../platform.h"

/**
 * Allocated block of memory. Contains the object header structure, and the actual payload data.
 * IMPORTANT: The payload is not a real pointer, it is the actual raw memory.
 */
typedef struct MemBlock {
    mem_index size;
    bool8 used;
    MemBlock *next;
    void *payload;
} MemBlock;

#define MEM_BLOCK_HEADER_SIZE (sizeof(MemBlock) - sizeof(void*))

/*
    Aligns the size to the machine word.

    Easier to explain with an example, let n = 3:
        003 (0000011) + 007 (0000111) = 010 (0001010)
        ~ 007 (0000111) = -8 (...1111000)
        010 (0001010) & -8 (...1111000) = 008 (0001000)
*/
static u64 AlignToMachineWord(u64 _n)
{
    return (_n + (sizeof(void*) - 1)) & (~(sizeof(void*) - 1));
}

/*
    Returns the memory block for the provided _payloadPtr payload pointer.
*/
static MemBlock* GetMemBlock(constptr void* _payloadPtr)
{
    assert(_payloadPtr != null);
    MemBlock *ret = (MemBlock *)((char *)_payloadPtr - MEM_BLOCK_HEADER_SIZE);
    return ret;
}

class BumpAllocator {
public:
    BumpAllocator();

    /*
        Tries to allocate a memory block with payload of _size.

        Returns a pointer to the payload.
    */
    Optional<void*> Allocate(mem_index _size);

    /*
        Deallocates the last allocated block.

        Returns 0 if successful, or a negative number if somthing failed.
    */
    Optional<bool8> DeallocateTopBlock();
private:
    /*
        Requests memory from the OS for the payload + the size of the memory block header.

        Returns a pointer to the allocated block, or a negative value indicating some error.
        Errors are platform specific.
    */
    Optional<MemBlock*> AllocMemoryBlock(mem_index _size);

    void* memAddr;
    MemBlock* top;
};

#endif