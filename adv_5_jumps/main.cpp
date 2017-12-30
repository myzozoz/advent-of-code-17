#include <iostream>
#include "jumps.h"


int main() {
    Jumps jumps("input.txt", 1);
    std::cout << "1st challenge jumps: " << jumps.jumpAll() << "\n";
    Jumps jumps2("input.txt", 2);
    std::cout << "2nd challenge jumps: " << jumps2.jumpAll() << "\n";
    return 0;
}