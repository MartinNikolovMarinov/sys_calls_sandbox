#include "err.h"

Error makeErr(i32 code, char *raw) {
    String msg = strMakeFromCharPtr(raw);
    Error ret = { .errorCode = code, .msg = &msg };
    return ret;
}

Error makeErrStr(i32 code, String *msg) {
    Error ret = { .errorCode = code, .msg = msg };
    return ret;
}

Error makeSuccess() {
    Error ret = { .errorCode = 0, .msg = null };
    return ret;
}

bool8 isSuccess(Error e) {
    bool8 ret = e.errorCode == 0;
    return ret;
}

char* syserrMsg(syserr e) {
    switch (e) {
        case SUCCESS: return "Success";
        case ENOMEM: return "Not enough space/cannot allocate memory";
        default:
            assert(false, "invalid syserr value"); // We don't know what the error is, hard panic program.
    }
    return ""; // unreachable.
}