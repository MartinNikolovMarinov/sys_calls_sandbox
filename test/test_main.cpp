// TODO: might use google test, if it can work without stdlib.

#include "../src/platform.h"
#include "../src/types.h"
#include "../src/raw_str.h"
#include "../src/str.h"
#include "../src/allocators/bump_allocator.h"

#define run_test(test) \
    test(#test)

#include "common_test_utils.cpp"
#include "str_tests.cpp"
#include "bump_allocator_tests.cpp"

i32 main(i32 argc, char** argv, char **envp) {
    constptr char* startMsg = "\n##### Running Tests #####\n\n";
    PltWrite(STDOUT, startMsg, StrLen(startMsg));

    if (run_test(RunAllStrTests) != true) {
        assertm(false, "string tests failed");
    }
    if (run_test(RunAllBumpAllocatorTests) != true) {
        assertm(false, "bump allocator tests failed");
    }

    return 0;
}
