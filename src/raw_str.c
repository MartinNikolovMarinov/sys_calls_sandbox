#include "raw_str.h"

i64 int32ToChar(char* out, i32 n) { return int64ToChar(out, n); }
i64 int64ToChar(char* out, i64 n)
{
    if (out == null) {
        return -1;
    }

    i64 wroteDigits = 0;
    i32 dc = digitCountI64(n);
    for (i32 i = dc - 1; i >= 0; i--)
    {
        i32 curr = (n / powI32(10, i)) % 10;
        *out = lsdI64ToChar(curr);
        out++;
        wroteDigits++;
    }

    return wroteDigits;
}

u64 rawStrLen(char* p)
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

/*
    Get the Least Significat Digit of an integer and cast to character.
*/
char lsdI32ToChar(i32 digit) { return (digit % 10) + '0'; }
char lsdI64ToChar(i64 digit) { return (digit % 10) + '0'; }