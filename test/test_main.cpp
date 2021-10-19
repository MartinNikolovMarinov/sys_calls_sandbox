// TODO: might use google test, if it can work without stdlib.

#include "../src/platform.h"
#include "../src/types.h"
#include "../src/raw_str.h"
#include "../src/str.h"

#include "str_tests.cpp"

#define run_test(test) \
    test(#test) \

i32 main(i32 argc, char** argv, char **envp) {
    constptr char* startMsg = "\n##### Running Tests #####\n\n";
    PltWrite(STDOUT, startMsg, StrLen(startMsg));
    run_test(RunAllStrTests);
    return 0;
}
