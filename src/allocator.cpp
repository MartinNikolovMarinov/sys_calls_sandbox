#include "allocator.h"

static void* startBrk;
static void* currBrk;

i32 initMemPool() {
    startBrk = sysbrk((void*)0);
    if (startBrk < 0) return -1;
    currBrk = startBrk;
    return 0;
}

void* allocate(i64 n) {
    assert(n > 0, "n must be positive");
    void *old = currBrk;
    void *newBrk = sysbrk((char*)currBrk + n);
    if (newBrk == currBrk || newBrk < 0) return (void*)-1;
    currBrk = newBrk;
    return old;
}

i32 deallocate(i64 n) {
    assert(n > 0, "n must be positive");
    assert((char*)currBrk - n >= startBrk, "trying to deallocated past the startBrk");
    void *newBrk = sysbrk((char*)currBrk - n);
    if (newBrk < 0) return -1;
    currBrk = newBrk;
    return 0;
}

i64 bytesAllocated() {
    i64 bytesAllocated = (i64)((char*)currBrk - (char*)startBrk);
    return bytesAllocated;
}

i32 clearMemoryPool() {
    i64 allocated = bytesAllocated();
    if (allocated <= 0) return 0;
    i32 ret = deallocate(allocated);
    return ret;
}
