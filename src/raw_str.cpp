#include "raw_str.h"

char LeastSignificatDigitI32ToChar(i32 digit) { return (digit % 10) + '0'; }
char LeastSignificatDigitI64ToChar(i64 digit) { return (digit % 10) + '0'; }

i64 I32ToChar(char* out, i32 n) { return I64ToChar(out, n); }
i64 I64ToChar(char* out, i64 n)
{
    if (out == null) {
        return -1;
    }

    i64 wroteDigits = 0;
    i32 dc = DigitCountI64(n);
    for (i32 i = dc - 1; i >= 0; i--)
    {
        i32 curr = (n / PowI32(10, i)) % 10;
        *out = LeastSignificatDigitI64ToChar(curr);
        out++;
        wroteDigits++;
    }

    return wroteDigits;
}

u64 StrLen(constptr char* p)
{
    if (p == null) {
        return 0;
    }

    u64 count = 0;
    while (*p != term_char) {
        p++;
        count++;
    }

    return count;
}