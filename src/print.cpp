#include "print.h"

Error printRawStr(char *str, u64 len) {
    if (len == 0) {
        len = rawStrLen(str);
    }
    u64 wrote = syswrite(STDOUT, str, len);
    if (wrote < 0) {
        return makeErr(-1, (char*)"write failed");
    } else if (wrote != len) {
        return makeErr(-2, (char*)"short write");
    }

    return makeSuccess();
}

Error printStr(String *str) {
    if (str == null) {
        return makeSuccess();
    }

    return printRawStr(str->_data, str->_size);
}