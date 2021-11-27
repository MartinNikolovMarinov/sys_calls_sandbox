#include "platform.h"

#if __unix__ && __x86_64__
    Optional<i64> PltWrite(i64 _fd, constptr void *_data, u64 _nbytes)
    {
        i64 ret = syswrite(_fd, (void*)_data, _nbytes);
        if (ret < 0) {
            return Optional<i64>(ret, "syswrite failed");
        }
        return Optional<i64>(ret, null);
    }
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

    Optional<void*> PltBumpAlloc(mem_index _size)
    {
        // TODO: NOT THREAD SAFE!!
        if (startBrk == null) {
            if (initMemPool() < 0) {
                assertm(false, "failed to initialize memory pool");
            }
        }

        void *old = currBrk;
        void *newBrk = sysbrk((char*)currBrk + _size);
        if (newBrk == currBrk || newBrk < 0) {
            return Optional<void*>(newBrk, "failed to allocate");
        }
        currBrk = newBrk;
        return Optional<void*>(old, null);
    }

    Optional<i64> PltBumpDeallocate(mem_index _size)
    {
        // TODO: NOT THREAD SAFE!!
        assertm((char*)currBrk - _size >= startBrk, "trying to deallocated past the startBrk");
        void *newBrk = sysbrk((char*)currBrk - _size);
        if (newBrk < 0) {
            return Optional<i64>((i64)newBrk, "deallocation failed");
        }
        currBrk = newBrk;
        return Optional<i64>(0, "");
    }
#else
    // not supported platform
#endif