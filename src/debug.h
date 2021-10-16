#ifndef DEBUG_H
#define DEBUG_H 1

#if defined(DEBUG) && (DEBUG == 1)
    #include "syscalls.h"
    #include "types.h"
    #include "raw_str.h"

    void __assertFailedHandler(char *file, i32 line);

    #define assert(expr) \
        if (!(expr)) \
            __assertFailedHandler(__FILE__, __LINE__)
#else
    #define assert(expression)
#endif

#endif