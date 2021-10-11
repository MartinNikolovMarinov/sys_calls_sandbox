#include "src/syscall_table.h"
#include "src/types.h"
#include "src/syscalls.h"
#include "src/raw_str.h"
#include "src/integers.h"

i32 main(i32 argc, char** argv)
{
    char buf[10];
    for (i32 i = 0; i < argc; i++)
    {
        u64 length = strLen(argv[i]);
        i32 wroteBytes = int64ToChar(buf, length);
        if (wroteBytes > 0) {
            write(STDOUT, argv[i], length);
            write(STDOUT, "\n", 1);
        } else {
            write(STDERR, "error", 5);
        }
    }

    return 0;
}