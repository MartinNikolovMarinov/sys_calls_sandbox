#ifndef SYSCALLS_H
#define SYSCALLS_H 1

#include "types.h"
#include "syscall_table.h"

u64 syswrite(i64 fd, void *data, u64 nbytes);
void sysexit(i64 code);
void* sysbrk(void *add);

#endif