#ifndef SYSCALLS_H
#define SYSCALLS_H 1

#include "syscall_table.h"
#include "types.h"

i64 syswrite(i64 fd, void *data, u64 nbytes);
void* sysbrk(void *add);

#endif