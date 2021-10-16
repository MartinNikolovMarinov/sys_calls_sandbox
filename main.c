#include "src/syscall_table.h"
#include "src/types.h"
#include "src/syscalls.h"
#include "src/raw_str.h"
#include "src/integers.h"
#include "src/allocator.h"
#include "src/debug.h"

i32 main(i32 argc, char** argv, char **envp)
{
    // TODO2: Start with implementing basic safe types.

    // TODO: make some structure to hold passed arguments.
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

    i32 ret = initMemPool();
    i32* integer = (i32*)allocate(100 * GIGABYTE);
    char* character = (char*)allocate(1);

    i32 bAlloced = bytesAllocated();

    // *integer = 0xFFFFFFFF;
    *character = 'p';

    ret = deallocate(sizeof(char));

    bAlloced = bytesAllocated();

    clearMemoryPool();
    bAlloced = bytesAllocated();

    // TODO: make some structure to hold the environment variables.
    // for (char **env = envp; *env != null; env++)
    // {
    //     char *curr = *env;
    //     i64 currLen = strLen(curr);
    //     syswrite(STDOUT, curr, currLen);
    //     syswrite(STDOUT, "\n", 1);
    // }

    return 0;
}