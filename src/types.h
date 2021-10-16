#ifndef TYPES_H
#define TYPES_H 1

#define local_persist static;
#define global_variable static;
/*
    IMPORTANT: (UNITY BUILD)
    If you don't mark a functions static, then the compiler needs to put it in a
    special symbol table for the linker. We don't care about it, because in a
    UNITY BUILD the linker will see only one file. So we can avoid the overhead
    of this special symbol table. This will make compilation faster and use less
    memory for compiler.
*/
#define internal static; // internal function

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

#define PI32 3.14159265359f

#define STDIN 0
#define STDOUT 1
#define STDERR 2

// TODO: Devies a more sophisticated error handling strategy:
#define SUCCESS 0
#define FAIL -1

// Storage Sizes
#define BYTE        ((i64)1)
#define KILOBYTE    ((i64)(1000 * BYTE))
#define MEGABYTE    ((i64)(1000 * KILOBYTE))
#define GIGABYTE    ((i64)(1000 * MEGABYTE))
#define TERABYTE    ((i64)(1000 * GIGABYTE))


#endif /* TYPES_H */