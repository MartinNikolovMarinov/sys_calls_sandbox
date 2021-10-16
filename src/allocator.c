#include "allocator.h"

static i64 startBrk;
static i64 currBrk;

i32 initMemPool() {
    startBrk = (i64)sysbrk((void*)0);
    if (startBrk < 0) return FAIL;
    currBrk = startBrk;
    return SUCCESS;
}

// TODO: finish bump allocator after assert.

void* allocate(i64 n) {
    sysbrk((void*)(startBrk + n));
    // if (n == 0) return memorypool;
    // void *old = memorypool;
    // memorypool = sysbrk(memorypool + n);
    // if (memorypool < 0) return (void*)-1;
    // bytesAllocated += n;
    // return old;
}

// i32 shrink(i64 n) {
//     void* res = sysbrk(memorypool - n);
//     if (res < 0) return -1;
//     return 1;
// }

// i32 clearMemoryPool() {
//     return shrink(bytesAllocated);
// }
