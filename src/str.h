#ifndef STR_H
#define STR_H 1

#include "types.h"
#include "raw_str.h"
#include "debug.h"
#include "integers.h"

typedef struct String {
    i64 _size, _cap;
    char *_data;
} String;

String strMake(char* buff, i64 size, i64 cap);
String strMakeFromCharPtr(char* buff);
i64 strSize(String *v);
i64 strCap(String *v);
void strCopy(String *src, String *dest);
void strConcat(String *a, String *b, String *out);
void strSetCharAt(String *src, i64 i, char a);
void strAddChar(String *src, char a);
void strSetAt(String *src, i64 srci, String *dest);
void strAdd(String *src, String *dest);

#endif