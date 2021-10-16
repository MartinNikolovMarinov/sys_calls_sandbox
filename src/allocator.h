#ifndef ALLOCATOR_H
#define ALLOCATOR_H 1

#include "types.h"
#include "syscalls.h"

i32 initMemPool();
void* allocate(i64 n);
i32 shrink(i64 n);
i32 clearMemoryPool();

#endif