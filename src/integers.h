#ifndef INTEGERS_H
#define INTEGERS_H 1

#include "types.h"

i32 digitCountI64(i64 n);
i32 digitCountI32(i32 n);

bool8 isInRangeI32(i64 start, i64 v, i64 end);
bool8 isInRangeI64(i64 start, i64 v, i64 end);
bool8 isInRangeI32Inclusive(i64 start, i64 v, i64 end);
bool8 isInRangeI64Inclusive(i64 start, i64 v, i64 end);

#endif