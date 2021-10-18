#ifndef DEBUG_H
#define DEBUG_H 1

#if defined(DEBUG) && (DEBUG == 1)
    #include "syscalls.h"
    #include "types.h"
    #include "raw_str.h"

    void __assertFailedHandler(constptr char *file, i32 line, constptr char* expr, constptr char* failMsg);

    #define assert(expr, failMsg)                                           \
        if (!(expr))                                                        \
            __assertFailedHandler(__FILE__, __LINE__, #expr, failMsg)
#else
    #define assert(expr)
#endif

#endif