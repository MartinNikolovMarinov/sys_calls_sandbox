#include "src/syscall_table.h"
#include "src/types.h"
#include "src/syscalls.h"
#include "src/raw_str.h"
#include "src/integers.h"
#include "src/allocator.h"
#include "src/debug.h"

i32 main(i32 argc, char** argv, char **envp)
{
    // char buf[10];
    // for (i32 i = 0; i < argc; i++)
    // {
    //     u64 length = strLen(argv[i]);
    //     i32 wroteBytes = int64ToChar(buf, length);
    //     if (wroteBytes > 0) {
    //         write(STDOUT, argv[i], length);
    //         write(STDOUT, "\n", 1);
    //     } else {
    //         write(STDERR, "error", 5);
    //     }
    // }

    // i32 ret = initMemPool();
    // i32* integer = (i32*)allocate(4);
    // char* character = (char*)allocate(1);

    // *integer = 0xFFFFFFF4;
    // *character = 'p';

    // *(character + 1) = 'c';
    // ret = shrink(sizeof(char));

    // *character = 't';

    // TODO: make some structure to hold the environment variables.
    for (char **env = envp; *env != null; env++)
    {
        char *curr = *env;
        i64 currLen = strLen(curr);
        syswrite(STDOUT, curr, currLen);
        syswrite(STDOUT, "\n", 1);
    }

    syswrite(STDOUT, "\n", 1);
    assert(false);
    syswrite(STDOUT, "\n", 1);
    return 0;
}