#include "src/types.h"
#include "src/raw_str.h"
#include "src/platform.h"
#include "src/allocators/bump_allocator.h"
#include "src/print.h"

i32 main(i32 argc, char** argv, char **envp)
{
    BumpAllocator ba;
    i64 *v1 = (i64*)ba.Allocate(16).val;
    MemBlock *memblock1 = GetMemBlock(v1);
    i32 *v2 = (i32*)ba.Allocate(4).val;
    MemBlock *memblock2 = GetMemBlock(v2);

    *v1 = INT64_MAX;
    *v2 = INT32_MAX;

    i32 ret;
    ret = ba.DeallocateTopBlock().val;
    memblock1 = GetMemBlock(v1);
    ret = ba.DeallocateTopBlock().val;
    ret = ba.DeallocateTopBlock().val;

    v2 = (i32*)ba.Allocate(4).val;
    Optional<void*> opt = ba.Allocate(-1);
    PrintOptionalError(opt);

    return 0;
}