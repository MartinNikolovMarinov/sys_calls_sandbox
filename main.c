#include "src/syscall_table.h"
#include "src/types.h"
#include "src/syscalls.h"
#include "src/raw_str.h"
#include "src/integers.h"
#include "src/allocator.h"
#include "src/debug.h"
#include "src/err.h"
#include "src/print.h"
#include "src/arr.h"

// TODO: Use this example macro to implement generic internal structures, like Array:
#define MAKE_ADDFN(TYPE)                                    \
TYPE add_##TYPE (TYPE a, TYPE b){                           \
    TYPE ret = a + b;                                       \
    return ret;                                             \
}

MAKE_ADDFN(i32);
MAKE_ADDFN(f32);
MAKE_ADDFN(f64);

// TODO: how is this possible ?
// #define get_string(n) #n
// char* p = get_string(Testing);

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

    // TODO: string tests:
    // char *banica = "banica";
    // String s1 = strMakeFromCharPtr(banica);
    // char buff[20];
    // String s2 = strMake(buff, 0, 20);
    // Error err;

    // strCopy(&s1, &s2);
    // strAdd(&s2, &s1);

    // if (!isSuccess(printStr(&s1)))
    //     sysexit(-1);
    // if (!isSuccess(printRawStr("\n", 0)))
    //     sysexit(-1);
    // if (!isSuccess(printStr(&s2)))
    //     sysexit(-1);
    // if (!isSuccess(printRawStr("\n", 0)))
    //     sysexit(-1);

    // TODO: maybe move to macro definitions insted of void pointer:
    // int intArr[5] = { 1, 2, 3, 4, 5 };
    // void* data = (void*)&intArr;
    // Array arr = arrMake(data, 5, sizeof(int));
    // void* p;
    // int v;
    // p = arrGetAt(&arr, 0);
    // v = *((int*)p);
    // p = arrGetAt(&arr, 1);
    // v = *((int*)p);
    // p = arrGetAt(&arr, 2);
    // v = *((int*)p);
    // p = arrGetAt(&arr, 3);
    // v = *((int*)p);
    // p = arrGetAt(&arr, 4);
    // v = *((int*)p);

    i32 a = add_i32(1, 2);
    f32 b = add_f32(1.1, 2.4);
    assert(a == 10, "uf bad hmm ?");
    return 0;
}