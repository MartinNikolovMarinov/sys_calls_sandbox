#include "integers.h"

i32 DigitCountI32(i32 n) { return DigitCountI64((i64)n); }
i32 DigitCountI64(i64 n)
{
    i32 ret = 0;
    while (n != 0) {
        n /= 10;
        ret++;
    }
    return ret;
}