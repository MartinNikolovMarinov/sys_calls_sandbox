#include "str.h"

void StrConcat(modtptr String *_out, constptr String *_strs...)
{
    assert(_out != null);

    va_list va;
    va_start(va, _strs);
    i32 outCap = _out->Cap();

    for (String *curr = (String *)_strs; curr != null; curr = va_arg(va, String*)) {
        assertm((_out->Size() + curr->Size() <= outCap), "trying to write past _out capacity");
        _out->Add(curr);
    }

    va_end(va);
    return;
}

String::String(modtptr char* _raw)
{
    assert(_raw != null);

    u64 len = StrLen(_raw);
    this->cap = len;
    this->size = len;
    this->data = _raw;
}

String::String(modtptr char* _raw, i64 _size, i64 _cap)
{
    assert(_raw != null);
    assert(_size >= 0);
    assert(_cap >= 0);
    assert(_cap >= _size);

    this->cap = _cap;
    this->size = _size;
    this->data = _raw;
}

String::String(modtptr String* _other)
{
    assert(_other != null);
    assert(_other->data != null);

    this->cap = _other->cap;
    this->size = _other->size;
    this->data = _other->data;
}

void String::Init() {
    this->cap = 0;
    this->size = 0;
}

i32 String::Cap()  { return this->cap;  }
i32 String::Size() { return this->size; }

void String::SetAt(i32 _index, char _v)
{
    assertm((0 <= _index && _index < this->size), "_index argument is in an invalid range");

    this->data[_index] = _v;
}

void String::SetAt(constptr String* _other, i32 _index)
{
    assert(_other != null);
    assertm((0 < _index && _index < this->size), "_index argument is in an invalid range");
    assertm((this->size + _index + _other->size >= this->cap), "not enough capacity to add _other string at _index");

    for (i64 i = 0; i < _other->size; i++) {
        this->data[i + this->size + _index] = _other->data[i];
    }
}

void String::Add(char _v)
{
    assertm((this->size + 1 <= this->cap), "trying to add a character past capacity");

    this->data[this->size] = _v;
    this->size++;
}

void String::Add(constptr String *_other)
{
    assert(_other != null);
    assertm((this->size + _other->size <= this->cap), "trying to add a string past capacity");

    i32 i = 0;
    while (i < _other->size) {
        this->data[i + this->size] = _other->data[i];
        i++;
    }
    this->size += i;
}

void String::SetData(modtptr char* _ptr, i64 _len) {
    assert(_ptr != null);
    if (_len <= 0) {
        _len = StrLen(_ptr);
    }
    assert(this->cap < _len);
    this->data = _ptr;
    this->size = _len;
}

void String::SetTo(constptr char* _ptr, i64 _len) {
    assert(_ptr != null);
    if (_len <= 0) {
        _len = StrLen(_ptr);
    }
    assert(this->cap < _len);
    for (i32 i = 0; i < _len; i++)
    {
        this->SetAt(i, _ptr[i]);
    }
}