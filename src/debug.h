#ifndef DEBUG_H
#define DEBUG_H 1

#if defined(DEBUG) && (DEBUG == 1)
    #include "platform.h"
    #include "raw_str.h"

    void __assertFailedHandler(constptr char *_file, i32 _line, constptr char *_expr, constptr char *_failMsg);

    #define assert(expr)                                                    \
        if (!(expr))                                                        \
            __assertFailedHandler(__FILE__, __LINE__, #expr, "")

    #define assertm(expr, errMsg)                                           \
        if (!(expr))                                                        \
            __assertFailedHandler(__FILE__, __LINE__, #expr, errMsg)
#else
    #define assert(expr)
    #define assertm(expr, errMsg)
#endif


#endif