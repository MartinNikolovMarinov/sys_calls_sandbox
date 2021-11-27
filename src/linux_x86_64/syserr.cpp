#include "syserr.h"

constptr char* TranslateSysError(syserr _e)
{
    switch (_e) {
        case SUCCESS: return "Success";
        case ENOMEM: return "Not enough space/cannot allocate memory";
        default: return "unknown";
    }
}