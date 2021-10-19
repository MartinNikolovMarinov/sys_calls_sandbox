#ifndef SYSCALLS_H
#define SYSCALLS_H 1

#include "types.h"

#if __unix__ && __x86_64__
    #include "unix/syscalls.h"
    #include "unix/syserr.h"
#else
    // not supported platform
#endif

// Common OS interface:
u64 PltWrite(i64 fd, constptr void *data, u64 nbytes);
void PltExit(i64 code);

#endif