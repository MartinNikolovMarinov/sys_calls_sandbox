#include "debug.h"

void __assertFailedHandler(char *file, i32 line) {
    i64 flen = strLen(file);
    char lineNumStr[500]; // TODO: fix when fix sized arrays are implemented.
    i64 wrote = int32ToChar(lineNumStr, line);

    syswrite(STDOUT, "ASSERTION FAILED at ", 20);
    syswrite(STDOUT, "file: ", 6);
    syswrite(STDOUT, file, flen);
    syswrite(STDOUT, "; line: ", 8);
    syswrite(STDOUT, lineNumStr, wrote);
    syswrite(STDOUT, "\n", 1);

    *(int *)0 = 0; // Crash the program by dereferencing address 0.
}