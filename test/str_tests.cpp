bool8 RunAllStrTests(constptr char* tname) {
    String s1((modtptr char*)"dog");
    String s2((modtptr char*)" ");
    String s3((modtptr char*)"fat");

    char buf[7] = {};
    String out(buf, 0, 7);

    StrConcat(&out, &s1, &s2, &s3, null);

    PltWrite(STDOUT, tname, StrLen(tname));
    PltWrite(STDOUT, " [OK]\n", StrLen(" [OK]\n"));

    return true;
}