#ifndef SYSCALLS_H
#define SYSCALLS_H 1

#include "syscall_table.h"
#include "types.h"

i64 write(i64 fd, void const* data, u64 nbytes);

#endif