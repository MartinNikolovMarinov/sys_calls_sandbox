#include "util.h"

u64 AlignToMachineWord(u64 n) {
    return (n + (sizeof(void*) - 1)) & (~(sizeof(void*) - 1));
}