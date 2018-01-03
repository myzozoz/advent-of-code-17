#include <iostream>
#include "circus.h"

#define FILENAME "input.txt"

int main () {
    Circus circus(FILENAME);
    std::cout << "Bottom tower: " << circus.bottom() << "\n";
    std::cout << "Unbalanced tower: " << circus.unbalanced() << "\n";
    std::cout << "Desired weight: " << circus.desiredWeight() << "\n";
    return 0;
}