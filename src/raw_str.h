#ifndef RAW_STR_H
#define RAW_STR_H 1

#include "types.h"
#include "math.h"
#include "integers.h"

u64 rawStrLen(char* p);
i64 int32ToChar(char* out, i32 n);
i64 int64ToChar(char* out, i64 n);
char lsdI32ToChar(i32 digit);
char lsdI64ToChar(i64 digit);

#endif