#include <iostream>
#include <cstdlib>

#include "registers.h"

int main (int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Invalid amount of arguments!\n";
        std::cerr << "Program accepts single argument 'input file name'\n";
        exit(1);
    }

    Registers regs(argv[1]);
    return 0;
}