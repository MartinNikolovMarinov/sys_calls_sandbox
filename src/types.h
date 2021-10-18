#ifndef TYPES_H
#define TYPES_H 1

// This include allowes the use of variadic functions.
// It is a 0 cost abstraction that defines a couple of macros.
// NOTE: It is not part of the stdlib.
#include <stdarg.h>

#define global_variable static  // Defined Global Variable marker macro
#define constptr const          // Constant Pointer marker macro
#define modtptr                 // Modifiable Pointer marker macro

typedef signed char i8;
typedef signed short int i16;
typedef signed int i32;
typedef signed long int i64;

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long int u64;

typedef float f32;
typedef long double f64;

typedef i8 bool8;

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