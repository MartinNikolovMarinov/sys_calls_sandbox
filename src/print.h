#ifndef PRINT_H
#define PRINT_H 1

#include "types.h"
#include "raw_str.h"
#include "platform.h"
#include "optional.h"

template<typename T>
void PrintOptionalError(Optional<T> _opt)
{
    if (_opt.err != null) {
        u64 len = StrLen(_opt.err);
        Optional<i64> optWrite = PltWrite(STDOUT, _opt.err, len);
        assert(optWrite.err == null); // should never fail to display optional error.
    } else {
        Optional<i64> optWrite = PltWrite(STDOUT, "success", StrLen("success"));
        assert(optWrite.err == null); // should never fail to display optional error.
    }
}

#endif