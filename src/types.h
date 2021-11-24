#ifndef TYPES_H
#define TYPES_H 1

// This include allowes the use of variadic functions.
// It is a 0 cost abstraction that defines a couple of macros.
// NOTE: It is not part of stdlib.
#include <stdarg.h>

// Include system defaults.
// NOTE: These are not part of stdlib.
#include <stdint.h>
#include <stddef.h>

/*
    IMPORTANT:
    It's best to avoid adding any includes to this file to avoid cyclic dependencies,
    because it is literarily included in every other file.
*/

#define global_variable static  // Defined Global Variable marker macro
#define constptr const          // Constant Pointer marker macro
#define modtptr                 // Modifiable Pointer marker macro

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef long double f64;

typedef i8 bool8;

// Pointer size specific types:
typedef size_t mem_index;

// Special constants :
#define true 1
#define false 0
#define null 0
#define term_char '\0'

#define STDIN 0
#define STDOUT 1
#define STDERR 2

// Storage Sizes
#define BYTE        ((i64)1)
#define KILOBYTE    ((i64)(1000 * BYTE))
#define MEGABYTE    ((i64)(1000 * KILOBYTE))
#define GIGABYTE    ((i64)(1000 * MEGABYTE))
#define TERABYTE    ((i64)(1000 * GIGABYTE))

#endif /* TYPES_H */