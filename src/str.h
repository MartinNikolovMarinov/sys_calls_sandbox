#ifndef STR_H
#define STR_H 1

#include "types.h"
#include "raw_str.h"
#include "debug.h"
#include "integers.h"

class String {
public:
    String(modtptr char* _raw);
    String(modtptr char* _raw, i64 _size, i64 _cap);
    String(modtptr String* _other);

    void Init();

    i32 Size();
    i32 Cap();
    void SetData(modtptr char* _ptr, i64 _len);
    void SetTo(constptr char* _ptr, i64 _len);
    void SetAt(i32 _i, char _v);
    void SetAt(constptr String* _other, i32 _i);
    void Add(char _v);
    void Add(constptr String* _other);
private:
    i32 size, cap;
    char* data;
};

void StrConcat(modtptr String *_out, constptr String *_strs...);

#endif