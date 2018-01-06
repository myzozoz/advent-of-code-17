#include "sprocessor.h"

#include <iostream>

int main (int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Please insert input filename as the only parameter\n";
    } else {
        SProcessor sprocessor(argv[1]);
    }
    return 0;
}