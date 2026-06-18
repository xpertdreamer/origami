// #define VERSION 0.01

#include "trex.h"

int main() {
    // demo
    char sym[] = {'a', 'b', 'c', 'd', 'e'};
    int freq[] = {60, 5, 30, 5, 45};
    int size = sizeof(sym) / sizeof(sym[0]);
    code(sym, freq, size);
    return 0;
}
