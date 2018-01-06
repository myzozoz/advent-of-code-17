#include <fstream>
#include <iostream>
#include <list>

#include "knot.h"

#define FILENAME1 "input.txt"
#define FILENAME2 "input2.txt"
#define LIST_SIZE 256

void initializeList(int* list);
void twist(int* list, int pos, int length);

int main () {
    std::ifstream fileStream(FILENAME1);

    int* list = new int[LIST_SIZE];

    initializeList(list);

    int length(0), pos(0), skip(0);
    while (fileStream >> length) {
        //twist
        twist(list, pos, length);
        //move position length + skip size
        pos = (pos + length + skip) % LIST_SIZE;
        //increment skip size
        skip++;
    }
    std::cout << "Part One:\n";
    std::cout << "Checksum: " << list[0] * list[1] << "\n";
    std::cout << "----------------\n";
    std::cout << "Part Two:\n";
    Knot knot(FILENAME2, LIST_SIZE);

    return 0;
}

void initializeList(int* list) {
    for (int i = 0; i < LIST_SIZE; i++) {
        list[i] = i;
    }
}

void twist(int* list, int pos, int length) {
    int* sublist = new int[length];
    for (int i = 0; i < length; i++) {
        sublist[i] = list[(pos + i) % LIST_SIZE];
    }

    for (int i = 0; i < length; i++) {
        list[(pos + i) % LIST_SIZE] = sublist[length - (i + 1)];
    }

    delete[] sublist;
}