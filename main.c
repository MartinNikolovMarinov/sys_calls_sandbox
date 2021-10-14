#include "src/syscall_table.h"
#include "src/types.h"
#include "src/syscalls.h"
#include "src/raw_str.h"
#include "src/integers.h"

// Block *requestFromOS(size_t size) {
//   auto block = (Block *)sbrk(0);                // (1)

//   syscall(SYSCALL_brk, 0, 0, 0, 0, 0);
//   sbrk()

//   // OOM.
//   if (sbrk(allocSize(size)) == (void *)-1) {    // (2)
//     return nullptr;
//   }

//   return block;
// }

/*
    IMPORTANT:

    If successful, brk() returns 0.

    If unsuccessful, brk() returns -1 and sets errno to one of the following values:
    Error Code
        Description
    ENOMEM
        The requested change would allocate more space than allowed for the calling process.

 */

static void *memorypool;

i32 initMemPool() {
    memorypool = (struct MemBlock*)syscall(SYSCALL_brk, 0, 0, 0, 0, 0);
    if (memorypool < 0) return -1;
    return 1;
}

void* allocate(int n) {
    if (n == 0) return memorypool;
    void *old = memorypool;
    memorypool = (void*)syscall(SYSCALL_brk, memorypool + n, 0, 0, 0, 0);
    if (memorypool < 0) return (void*)-1;
    return old;
}

i32 resetMemPool(){
    void* res = syscall(SYSCALL_brk, memorypool, 0, 0, 0, 0);
    if (res < 0) return -1;
    return 1;
}

i32 main(i32 argc, char** argv)
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

    initMemPool();
    int* integer = (int*)allocate(4);
    char* character = (char*)allocate(1);

    *integer = 0xFFFFFFF4;
    *character = 'p';

    *(character + 1) = 'c';

    return 0;
}