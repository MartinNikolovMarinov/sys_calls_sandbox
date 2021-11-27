void PrintTestOK(constptr char* tname) {
    PltWrite(STDOUT, tname, StrLen(tname));
    PltWrite(STDOUT, " [OK]\n", StrLen(" [OK]\n"));
}