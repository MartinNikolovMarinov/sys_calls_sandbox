#ifndef ERR_H
#define ERR_H 1

#include "types.h"
#include "str.h"

/* Slow Error Handling: */

typedef struct Error {
    i32 errorCode;
    String *msg;
} Error;

Error makeErr(i32 code, char *raw);
Error makeErrStr(i32 code, String *msg);
Error makeSuccess();
bool8 isSuccess(Error e);

/* FAST Error handling: */

typedef enum syserr {
    SUCCESS = 0,
    ENOMEM = 12
} syserr;

constptr char* syserrMsg(syserr e);

#endif