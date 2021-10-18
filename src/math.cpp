#include "math.h"

i64 powI32(i32 n, i32 power)    { return (i64)powF64((f64)n, power); }
i64 powI64(i64 n, i32 power)    { return (i64)powF64(n, power);      }
f32 powF32(f32 n, i32 power)    { return (f32)powF64((f64)n, power); }
f64 powF64(f64 n, i32 power)
{
    if (power < 0) {
        power = -power;
        n = 1/n;
    }

    f64 res = 1;
    for (i32 i = 0; i < power; i++)
    {
        res = res * n;
    }

    return res;
}