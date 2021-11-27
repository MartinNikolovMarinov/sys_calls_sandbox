#ifndef SYSERR_H
#define SYSERR_H 1

#include "../types.h"

/* FAST Error handling: */
typedef enum syserr {
    SUCCESS = 0,
    ENOMEM = 12
} syserr;

constptr char* syserrMsg(syserr _e);

#endif