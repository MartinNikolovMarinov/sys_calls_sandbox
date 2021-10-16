#include "allocator.h"

static void* startBrk;
static void* currBrk;

i32 initMemPool() {
    startBrk = sysbrk((void*)0);
    if (startBrk < 0) return FAIL;
    currBrk = startBrk;
    return SUCCESS;
}

void* allocate(i64 n) {
    assert(n > 0, "n must be positive");
    void *old = currBrk;
    void *new = sysbrk(currBrk + n);
    if (new == currBrk || new < 0) return (void*)FAIL;
    currBrk = new;
    return old;
}

i32 deallocate(i64 n) {
    assert(n > 0, "n must be positive");
    assert(currBrk - n >= startBrk, "trying to deallocated past the startBrk");
    void *new = sysbrk(currBrk - n);
    if (new < 0) return FAIL;
    currBrk = new;
    return SUCCESS;
}

i64 bytesAllocated() {
    i64 bytesAllocated = (i64)(currBrk - startBrk);
    return bytesAllocated;
}

i32 clearMemoryPool() {
    i64 allocated = bytesAllocated();
    if (allocated <= 0) return SUCCESS;
    i32 ret = deallocate(allocated);
    return ret;
}
