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