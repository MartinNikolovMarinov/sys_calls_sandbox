#include "syscalls.h"

u64 syswrite(i64 fd, void *data, u64 nbytes)
{
    u64 res = (u64)syscall(SYSCALL_write,
                            (void*)fd,
                            (void*)data,
                            (void*)nbytes,
                            0, /* ignored */
                            0  /* ignored */);
    return res;
}

void sysexit(i64 code)
{
    syscall(SYSCALL_exit, (void*)code, 0, 0, 0, 0);
}

void* sysbrk(void *addr)
{
    void* ret = (void*)syscall(SYSCALL_brk, addr, 0, 0, 0, 0);
    return ret;
}