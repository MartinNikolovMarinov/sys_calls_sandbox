#ifndef ARR_H
#define ARR_H 1

#include "types.h"
#include "debug.h"

typedef struct Array {
    u64 _size;
    u64 _typeSize;
    void *_data;
} Array;

Array arrMake(void *data, u64 size, u64 typeSize);
void* arrGetAt(Array *arr, u64 index);

#endif