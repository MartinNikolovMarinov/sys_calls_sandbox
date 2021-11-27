#include "raw_str.h"

char LeastSignificatDigitI32ToChar(i32 _digit) { return (_digit % 10) + '0'; }
char LeastSignificatDigitI64ToChar(i64 _digit) { return (_digit % 10) + '0'; }

i64 I32ToChar(char* _out, i32 _n) { return I64ToChar(_out, _n); }
i64 I64ToChar(char* _out, i64 _n)
{
    assert(_out != null);
    i64 wroteDigits = 0;
    i32 dc = DigitCountI64(_n);
    for (i32 i = dc - 1; i >= 0; i--)
    {
        i32 curr = (_n / PowI32(10, i)) % 10;
        *_out = LeastSignificatDigitI64ToChar(curr);
        _out++;
        wroteDigits++;
    }

    return wroteDigits;
}

u64 StrLen(constptr char* _p)
{
    assert(_p != null);
    u64 count = 0;
    while (*_p != term_char) {
        _p++;
        count++;
    }

    return count;
}