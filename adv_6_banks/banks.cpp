#include "banks.h"


Banks::Banks(std::string fileName, int amountOfBanks) {
    bankCount = amountOfBanks;
    readFile(fileName);
    foundMap[stringify()] = 0;
}

void Banks::testPrint() {
    std::cout << stringify() << "\n";
}

void Banks::readFile(std::string fileName) {
    assert(!fileName.empty());
    banks = new int[bankCount];

    std::ifstream fileStream(fileName);

    int i = 0;
    while (fileStream) {
        fileStream >> banks[i];
        i++;
    }
}

int Banks::solve() {
    int iterations = 0;
    while (true) {
        level();
        iterations++;
        //enable testPrint call below to have the program print each step
        //testPrint();

        //see if combination is already found
        if (foundMap.count(stringify())) {
            //enable/disable following line depending on challenge part
            //(disabled is part 1)
            return iterations - foundMap[stringify()];
            break;
        } else {
            foundMap[stringify()] = iterations;
        }
    }

    return iterations;
}

void Banks::level() {
    //find largest bank (if equal select lowest order) and store the amnt of blocks
    int i_largestBank = findHighest();
    int blocks = banks[i_largestBank];
    //empty the bank
    banks[i_largestBank] = 0;
    //add a block to each bank in order starting from next
    distribute(blocks, i_largestBank + 1);
}

void Banks::distribute(int blocks, int start) {
    while (blocks > 0) {
        banks[start % bankCount] = banks[start % bankCount] + 1;
        start++;
        blocks--;
    }
}

int Banks::findHighest() {
    int found = 0;
    for (int i = 0; i < bankCount; i++) {
        if (banks[i] > banks[found]) {
            found = i;
        }
    }

    return found;
}

std::string Banks::stringify() {
    std::string stringified = "";
    for (int i = 0; i < bankCount; i++) {
        stringified += std::to_string(banks[i]);
    }
    return stringified;
}