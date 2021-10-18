#ifndef RAW_STR_H
#define RAW_STR_H 1

#include "types.h"
#include "math.h"
#include "integers.h"

u64 StrLen(constptr char* p);
i64 I32ToChar(modtptr char* out, i32 n);
i64 I64ToChar(modtptr char* out, i64 n);
char LeastSignificatDigitI32ToChar(i32 digit);
char LeastSignificatDigitI64ToChar(i64 digit);

#endif