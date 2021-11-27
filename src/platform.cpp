#include "platform.h"

#if __unix__ && __x86_64__
    u64 PltWrite(i64 _fd, constptr void *_data, u64 _nbytes) { return syswrite(_fd, (void*)_data, _nbytes); }
    void PltExit(i64 _code) { sysexit(_code); }

    static void* startBrk;
    static void* currBrk;

    i32 initMemPool()
    {
        startBrk = sysbrk((void*)0);
        if (startBrk < 0) return -1;
        currBrk = startBrk;
        return 0;
    }

    void* PltBumpAlloc(mem_index _size)
    {
        // TODO: NOT THREAD SAFE!!
        if (startBrk == null) {
            if (initMemPool() < 0) {
                assertm(false, "failed to initialize memory pool");
            }
        }

        void *old = currBrk;
        void *newBrk = sysbrk((char*)currBrk + _size);
        if (newBrk == currBrk || newBrk < 0) return (void*)-1;
        currBrk = newBrk;
        return old;
    }

    i32 PltBumpDeallocate(mem_index _size)
    {
        // TODO: NOT THREAD SAFE!!
        assertm((char*)currBrk - _size >= startBrk, "trying to deallocated past the startBrk");
        void *newBrk = sysbrk((char*)currBrk - _size);
        if (newBrk < 0) return -1;
        currBrk = newBrk;
        return 0;
    }
#else
    // not supported platform
#endif