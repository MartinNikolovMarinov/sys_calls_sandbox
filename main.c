#include "src/syscall_table.h"
#include "src/types.h"
#include "src/syscalls.h"
#include "src/raw_str.h"
#include "src/integers.h"
#include "src/allocator.h"
#include "src/debug.h"
#include "src/err.h"
#include "src/print.h"

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

    // TODO: update memory pool to be able to free memory.
    // i32 ret = initMemPool();
    // i32* integer = (i32*)allocate(sizeof(i32));
    // char* character = (char*)allocate(sizeof(char));

    // i32 bAlloced = bytesAllocated();

    // *integer = 0xFFFFFFFF;
    // *character = 'p';

    // ret = deallocate(sizeof(char));

    // bAlloced = bytesAllocated();

    // clearMemoryPool();
    // bAlloced = bytesAllocated();

    // TODO: make some structure to hold the environment variables.
    // for (char **env = envp; *env != null; env++)
    // {
    //     char *curr = *env;
    //     i64 currLen = strLen(curr);
    //     syswrite(STDOUT, curr, currLen);
    //     syswrite(STDOUT, "\n", 1);
    // }

    char *banica = "banica";
    String s1 = strMakeFromCharPtr(banica);
    char buff[20];
    String s2 = strMake(buff, 0, 20);
    Error err;

    strCopy(&s1, &s2);
    strAdd(&s2, &s1);

    if (!isSuccess(printStr(&s1)))
        sysexit(-1);
    if (!isSuccess(printRawStr("\n", 0)))
        sysexit(-1);
    if (!isSuccess(printStr(&s2)))
        sysexit(-1);
    if (!isSuccess(printRawStr("\n", 0)))
        sysexit(-1);

    return 0;
}