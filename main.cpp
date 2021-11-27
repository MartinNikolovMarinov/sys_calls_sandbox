#include "src/types.h"
#include "src/raw_str.h"
#include "src/platform.h"
#include "src/allocators/bump_allocator.h"
#include "src/err.h"

i32 main(i32 argc, char** argv, char **envp)
{
    BumpAllocator ba;
    i64 *v1 = (i64*)ba.Allocate(16);
    MemBlock *memblock1 = GetMemBlock(v1);
    i32 *v2 = (i32*)ba.Allocate(4);
    MemBlock *memblock2 = GetMemBlock(v2);

    *v1 = INT64_MAX;
    *v2 = INT32_MAX;

    i32 ret;
    ret = ba.DeallocateTopBlock();
    memblock1 = GetMemBlock(v1);
    ret = ba.DeallocateTopBlock();
    ret = ba.DeallocateTopBlock();

    v2 = (i32*)ba.Allocate(4);
    v1 = (i64*)ba.Allocate(8);

    *v1 = INT64_MAX;
    *v2 = INT32_MAX;

    // Block b;
    // char out[100];
    // i64 wrote = I64ToChar(out, 8*4 - sizeof(void*));
    // PltWrite(STDOUT, out, wrote);
    // PltWrite(STDOUT, "\n", 1);

    // i32 size = __SIZE_MAX__;
    // char largestBuff[100000000];
    // i64 size1 = sizeof largestBuff;
    // i32 size2 = sizeof largestBuff;
    // u64 size3 = sizeof largestBuff;
    // u32 size4 = sizeof largestBuff;
    // u16 size5 = sizeof largestBuff;

    // i32 wrote = I32ToChar(sizeAsCharPtr, size);
    // wrote = PltWrite(STDOUT, sizeAsCharPtr, wrote);

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

    return 0;
}