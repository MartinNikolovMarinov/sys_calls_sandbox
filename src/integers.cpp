#include "integers.h"

i32 digitCountI32(i32 n) { return digitCountI64((i64)n); }
i32 digitCountI64(i64 n)
{
    i32 ret = 0;
    while (n != 0) {
        n /= 10;
        ret++;
    }
    return ret;
}

bool8 isInRangeI32(i64 start, i64 v, i64 end) { return isInRangeI64((i64)start, (i64)v, (i64)end); }
bool8 isInRangeI64(i64 start, i64 v, i64 end) { return (start < v && v < end); }
bool8 isInRangeI32Inclusive(i64 start, i64 v, i64 end) { return isInRangeI64Inclusive((i64)start, (i64)v, (i64)end); }
bool8 isInRangeI64Inclusive(i64 start, i64 v, i64 end) { return (start <= v && v <= end);}