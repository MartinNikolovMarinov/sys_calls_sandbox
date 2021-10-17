#include "print.h"

Error printRawStr(char *str, u64 len) {
    if (len == 0) {
        len = rawStrLen(str);
    }
    i64 wrote = syswrite(STDOUT, str, len);
    if (wrote < 0) {
        return makeErr(-1, "write failed");
    } else if (wrote != len) {
        return makeErr(-2, "short write");
    }

    return makeSuccess();
}

Error printStr(String *str) {
    if (str == null) {
        return makeSuccess();
    }

    return printRawStr(str->_data, str->_size);
}