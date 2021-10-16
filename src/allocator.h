#ifndef ALLOCATOR_H
#define ALLOCATOR_H 1

#include "types.h"
#include "syscalls.h"
#include "debug.h"

i32 initMemPool();
i32 clearMemoryPool();
void* allocate(i64 n);
i32 deallocate(i64 n);
i64 bytesAllocated();

#endif