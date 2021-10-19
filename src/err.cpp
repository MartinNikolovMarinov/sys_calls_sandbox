#include "err.h"

Error::Error() : code(0), err(null) {}
Error::Error(i32 _code, constptr char* _err) : code(_code), err(_err) {}

bool8 Error::IsSuccess() { return (code == 0); }