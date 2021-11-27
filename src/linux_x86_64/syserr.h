#ifndef SYSERR_H
#define SYSERR_H 1

#include "../types.h"

typedef enum syserr {
    SUCCESS = 0,
    ENOMEM = 12
} syserr;

constptr char* TranslateSysError(syserr _e);

#endif