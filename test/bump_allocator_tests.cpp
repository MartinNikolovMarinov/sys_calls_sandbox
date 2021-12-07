bool8 BumpAllocatorBasicTest(constptr char* tname) {
    BumpAllocator ba;
    i64 *v1 = (i64*)ba.Allocate(8).val;
    MemBlock *memblock1 = GetMemBlock(v1);
    i32 *v2 = (i32*)ba.Allocate(4).val;
    MemBlock *memblock2 = GetMemBlock(v2);

    *v1 = INT64_MAX;
    *v2 = INT32_MAX;

    assert(*v1 == INT64_MAX);
    assert(*v2 == INT32_MAX);

    Optional<bool8> opt;
    opt = ba.DeallocateTopBlock();
    assert(opt.err == null && opt.val == true);
    opt = ba.DeallocateTopBlock();
    assert(opt.err == null && opt.val == true);
    opt = ba.DeallocateTopBlock();
    assert(StrCmp(opt.err, "nothing to deallocate") == 0 && opt.val == false);

    v2 = (i32*)ba.Allocate(4).val;

    PrintTestOK(tname);
    return true;
}

bool8 BumpAllocatorWithStringTest(constptr char* tname) {
    BumpAllocator ba;
    String* str = (String*)ba.Allocate(sizeof(String)).val;
    str->Init();
    char* data = (char*)ba.Allocate(sizeof(char) * 10).val;
    str->SetData(data, 10);
    str->SetTo("testing", 0);

    u64 strSize = AlignToMachineWord(sizeof(String));
    u64 dataSize = AlignToMachineWord(sizeof(char) * 10);
    assert(ba.bytesAllocatedWithoutHeaders == (strSize + dataSize));

    Optional<bool8> opt;
    opt = ba.DeallocateTopBlock();
    assert(opt.err == null && opt.val == true);
    opt = ba.DeallocateTopBlock();
    assert(opt.err == null && opt.val == true);

    assert(ba.bytesAllocated == 0);
    assert(ba.bytesAllocatedWithoutHeaders == 0);

    PrintTestOK(tname);
    return true;
}

bool8 RunAllBumpAllocatorTests(constptr char* tname) {
    if (run_test(BumpAllocatorBasicTest) != true) {
        return false;
    }
    if (run_test(BumpAllocatorWithStringTest) != true) {
        return false;
    }
    return true;
}