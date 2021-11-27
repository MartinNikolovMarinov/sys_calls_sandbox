bool8 RunStrBasicTest(constptr char* tname) {
    String s1((modtptr char*)"dog");
    String s2((modtptr char*)" ");
    String s3((modtptr char*)"fat");

    char buf[7] = {};
    String out(buf, 0, 7);

    StrConcat(&out, &s1, &s2, &s3, null);

    PrintTestOK(tname);
    return true;
}

bool8 RunAllStrTests(constptr char* tname) {
    if (run_test(RunStrBasicTest) != true) {
        return false;
    }
    return true;
}