#include "debug.h"

#if defined(DEBUG) && (DEBUG == 1)

void __assertFailedHandler(constptr char *file, i32 line, constptr char *expr, constptr char *failMsg) {
    i64 flen = rawStrLen(file);
    i64 exprlen = rawStrLen(expr);
    i64 fmlen = rawStrLen(failMsg);
    char lineNumStr[500]; // TODO: fix when fix sized arrays are implemented.
    i64 wrote = int32ToChar(lineNumStr, line);

    // TODO: fix constant system calls once formatting is done.
    syswrite(STDOUT, (void*)"ASSERTION FAILED at ", 20);
    syswrite(STDOUT, (void*)"file: ", 6);
    syswrite(STDOUT, (void*)file, flen);
    syswrite(STDOUT, (void*)"; line: ", 8);
    syswrite(STDOUT, (void*)lineNumStr, wrote);
    syswrite(STDOUT, (void*)"; msg: ", 7);
    syswrite(STDOUT, (void*)failMsg, fmlen);
    syswrite(STDOUT, (void*)"; expr: ( ", 10);
    syswrite(STDOUT, (void*)expr, exprlen);
    syswrite(STDOUT, (void*)" )\n", 3);

    *(int *)0 = 0; // Crash the program by dereferencing address 0.
}

#endif