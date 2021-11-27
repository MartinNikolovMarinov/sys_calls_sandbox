#ifndef RAW_STR_H
#define RAW_STR_H 1

#include "types.h"
#include "math.h"
#include "integers.h"
#include "debug.h"

u64 StrLen(constptr char* _p);
i64 I32ToChar(modtptr char* _out, i32 _n);
i64 I64ToChar(modtptr char* _out, i64 _n);
i32 StrCmp(constptr char* _a, constptr char* _b);
char LeastSignificatDigitI32ToChar(i32 _digit);
char LeastSignificatDigitI64ToChar(i64 _digit);

#endif