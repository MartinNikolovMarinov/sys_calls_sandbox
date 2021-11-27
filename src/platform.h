#ifndef SYSCALLS_H
#define SYSCALLS_H 1

#include "types.h"
#include "debug.h"

#if __linux__ && __x86_64__
    #include "linux_x86_64/syscalls.h"
    #include "linux_x86_64/syserr.h"
#else
    // not supported platform
#endif

// Common OS interface:
u64 PltWrite(i64 _fd, constptr void *_data, u64 _nbytes);
void PltExit(i64 _code);
void* PltBumpAlloc(mem_index _size);
i32 PltBumpDeallocate(mem_index _n);

#endif