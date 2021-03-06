#ifndef LINUX_SYSCALLS_H
#define LINUX_SYSCALLS_H 1

#include "syscall_table.h"
#include "../types.h"

i64 syswrite(i64 fd, void *data, u64 nbytes);
void sysexit(i64 code);
void* sysbrk(void *addr);

#endif