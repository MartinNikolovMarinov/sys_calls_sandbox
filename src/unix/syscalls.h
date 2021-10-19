#ifndef UNIX_SYSCALLS_H
#define UNIX_SYSCALLS_H 1

#include "syscall_table.h"
#include "../types.h"

u64 syswrite(i64 fd, void *data, u64 nbytes);
void sysexit(i64 code);
void* sysbrk(void *addr);

#endif