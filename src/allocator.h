#ifndef ALLOCATOR_H
#define ALLOCATOR_H 1

#include "types.h"
// #include "syscalls.h"
// #include "debug.h"

// typedef void* (*allocatorFn)(i64 n);

// i32 initMemPool();
// i32 clearMemoryPool();
// void* allocate(i64 n);
// i32 deallocate(i64 n);
// i64 bytesAllocated();

/**
 * Allocated block of memory. Contains the object header structure,
 * and the actual payload pointer.
 */
typedef struct Block {
  mem_index size;
  bool8 used;
  Block *next;
  void *payload;
} Block;

#endif