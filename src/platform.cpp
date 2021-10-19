#include "platform.h"

#if __unix__ && __x86_64__
    u64 PltWrite(i64 fd, constptr void *data, u64 nbytes) { return syswrite(fd, (void*)data, nbytes); }
    void PltExit(i64 code) { sysexit(code); }
#else
    // not supported platform
#endif