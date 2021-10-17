#include "arr.h"

Array arrMake(void *data, u64 size, u64 typeSize) {
    assert(data != null, "data argument can't be null");
    Array ret = { ._data = data, ._size = size, ._typeSize = typeSize };
    return ret;
}

void* arrGetAt(Array *arr, u64 index) {
    assert(arr != null, "arr argument can't be null");
    assert(arr->_size > index, "index argument is out of range");
    void *ret = (void*)((char*)arr->_data + arr->_typeSize * index);
    return ret;
}