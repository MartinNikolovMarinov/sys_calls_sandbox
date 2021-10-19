#ifndef ERR_H
#define ERR_H 1

#include "types.h"

/* Verbose Error Handling: */
class Error {
public:
    i32 code;
    constptr char* err;

    Error();
    Error(i32 _code, constptr char* _err);

    bool8 IsSuccess();
};

#endif