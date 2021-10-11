#include "syscalls.h"

i64 write(i64 fd, void const* data, u64 nbytes)
{
    i64 res = (i64)syscall(SYSCALL_write,
                     (void*)fd,
                     (void*)data,
                     (void*)nbytes,
                     0, /* ignored */
                     0  /* ignored */);
    return res;
}