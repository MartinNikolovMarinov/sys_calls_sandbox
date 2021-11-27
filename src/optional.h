#ifndef OPTIONAL_H
#define OPTIONAL_H 1

#include "types.h"

template<typename T>
class Optional {
public:
    T val;
    constptr char* err;

    Optional(T _val, constptr char* _err) : val(_val), err(_err) {}
};

#endif