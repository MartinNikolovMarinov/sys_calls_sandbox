#include "str.h"

String strMake(char* buff, i64 size, i64 cap) {
    assert(buff != null, "buff argument can't be null");
    assert(size >= 0, "size can't be less than 0");
    assert(cap >= 0, "cap can't be less than 0");
    assert(cap >= size, "cap must be greater than or equal to size");

    String ret = { ._data = buff, ._size = size, ._cap = cap };
    return ret;
}

String strMakeFromCharPtr(char* buff) {
    assert(buff != null, "buff argument can't be null");
    i64 len = rawStrLen(buff);
    assert(len > 0, "len can't be null");

    String ret = { ._data = buff, ._size = len, ._cap = len };
    return ret;
}

i64 strSize(String *v) {
    i64 ret = v == null ? 0 : v->_size;
    return ret;
}

i64 strCap(String *v) {
    i64 ret = v == null ? 0 : v->_cap;
    return ret;
}

void strCopy(String *src, String *dest) {
    assert(src != null, "src argument can't be null");
    assert(dest != null, "dest argument can't be null");

    i64 i = 0;
    while (true) {
        if (i >= src->_size || i >= dest->_cap) {
            break;
        }
        strAddChar(dest, src->_data[i]);
        i++;
    }
}

void strConcat(String *a, String *b, String *out) {
    assert(a != null, "a argument can't be null");
    assert(b != null, "b argument can't be null");
    assert(out != null, "out argument can't be null");
    assert(a->_size + b->_size <= out->_cap, "out argument does not have enough space for the concatenation.");

    i64 i, outIndex;
    for (i = 0; i < a->_size; i++)
    {
        out->_data[outIndex] = a->_data[i];
        outIndex++;
    }
    for (i = 0; i < a->_size; i++)
    {
        out->_data[outIndex] = a->_data[i];
        outIndex++;
    }
    out->_size = outIndex;
}

void strSetCharAt(String *src, i64 i, char a) {
    assert(src != null, "src argument can't be null");
    assert(isInRangeI64(0, i, src->_size), "i argument is in an invalid range");

    src->_data[i] = a;
}

void strAddChar(String *src, char a) {
    assert(src != null, "src argument can't be null");
    assert(src->_size + 1 <= src->_cap, "trying to add a character past the capacity of the string");

    src->_data[src->_size] = a;
    src->_size++;
}

void strSetAt(String *src, i64 srci, String *dest) {
    assert(src != null, "src argument can't be null");
    assert(dest != null, "dest argument can't be null");
    assert(isInRangeI64(0, srci, src->_size), "srci argument is in an invalid range");
    assert(src->_size + srci + dest->_size >= src->_cap,
        "src string does not have enough capacity to add dest string at that location");

    i64 ssize = src->_size;
    char* sdata = src->_data;
    i64 dsize = dest->_size;
    char* ddata = dest->_data;
    for (i64 i = 0; i < dsize; i++)
    {
        sdata[i + ssize + srci] = ddata[i];
    }
}

void strAdd(String *src, String *dest) {
    assert(src != null, "src argument can't be null");
    assert(dest != null, "dest argument can't be null");
    assert(src->_size + dest->_size <= src->_cap, "src string does not have enough capacity to add dest string");

    i64 ssize = src->_size;
    char* sdata = src->_data;
    i64 dsize = dest->_size;
    char* ddata = dest->_data;
    for (i64 i = 0; i < dsize; i++)
    {
        sdata[i + ssize] = ddata[i];
        src->_size++;
    }

    assert(src->_size <= src->_cap, "sanity check failed");
}