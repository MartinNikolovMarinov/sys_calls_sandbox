#include "debug.h"

#if defined(DEBUG) && (DEBUG == 1)

// writeToStdOut might duplicate some logic, but debug.h needs to be self contained and
// depending on as few things as possible.
static void writeToStdOut(constptr char* data) {
    i32 len = StrLen(data);
    PltWrite(STDOUT, (void*)data, len); // if this fails there is nothing to do really..
}

void __assertFailedHandler(constptr char *_file, i32 _line, constptr char *_expr, constptr char *_failMsg) {
    char lineNumStr[500];
    i64 wrote = I32ToChar(lineNumStr, _line);
    lineNumStr[wrote] = '\0';

    // Probably not great that I am making all these system calls, but when
    // this code is called, next thing that happens is a forced crash, so meh..
    writeToStdOut("[ASSERTION FAILED]");
    writeToStdOut(" [FILE] ");
    writeToStdOut(_file);
    writeToStdOut(" [LINE] ");
    writeToStdOut(lineNumStr);
    writeToStdOut(" [EXPR] ");
    writeToStdOut(_expr);
    writeToStdOut(" [MSG] ");
    writeToStdOut(_failMsg);
    writeToStdOut("\n");

    *(int *)0 = 0; // Crash the program by dereferencing address 0.
}

#endif