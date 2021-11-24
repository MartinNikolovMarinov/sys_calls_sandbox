#ifndef UTIL_H
#define UTIL_H 1

#include "types.h"

/*
    Aligns the size by the machine word.

    Easier to explain with an example, let n = 3:
        003 (0000011) + 007 (0000111) = 010 (0001010)
        ~ 007 (0000111) = -8 (...1111000)
        010 (0001010) & -8 (...1111000) = 008 (0001000)
*/
u64 AlignToMachineWord(u64 _n);

#endif