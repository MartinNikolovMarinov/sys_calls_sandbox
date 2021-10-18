#include "debug.h"

#if defined(DEBUG) && (DEBUG == 1)

void __assertFailedHandler(char *file, i32 line, char *expr, char *failMsg) {
    i64 flen = rawStrLen(file);
    i64 exprlen = rawStrLen(expr);
    i64 fmlen = rawStrLen(failMsg);
    char lineNumStr[500]; // TODO: fix when fix sized arrays are implemented.
    i64 wrote = int32ToChar(lineNumStr, line);

    // TODO: fix constant system calls once formatting is done.
    syswrite(STDOUT, "ASSERTION FAILED at ", 20);
    syswrite(STDOUT, "file: ", 6);
    syswrite(STDOUT, file, flen);
    syswrite(STDOUT, "; line: ", 8);
    syswrite(STDOUT, lineNumStr, wrote);
    syswrite(STDOUT, "; msg: ", 7);
    syswrite(STDOUT, failMsg, fmlen);
    syswrite(STDOUT, "; expr: ( ", 10);
    syswrite(STDOUT, expr, exprlen);
    syswrite(STDOUT, " )\n", 3);

    *(int *)0 = 0; // Crash the program by dereferencing address 0.
}

#endif