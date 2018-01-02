#include <iostream>
#include "banks.h"

int main() {
    Banks banks("input.txt", 16);
    std::cout << banks.solve() << "\n";
    return 0;
}