#include "print.h"

Error printRawStr(char *str, u64 len) {
    if (len == 0) {
        len = rawStrLen(str);
    }
    i64 wrote = syswrite(STDOUT, str, len);
    if (wrote < 0) {
        String msg = strMakeFromCharPtr("write failed");
        return makeErr(-1, &msg);
    } else if (wrote != len) {
        String msg = strMakeFromCharPtr("short write");
        return makeErr(-2, &msg);
    }

    return makeSuccess();
}

Error printStr(String *str) {
    if (str == null) {
        return makeSuccess();
    }

    return printRawStr(str->_data, str->_size);
}