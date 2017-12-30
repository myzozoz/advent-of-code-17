#include "jumps.h"

Jumps::Jumps(std::string fileName, int nr) {
    rowCount = countRows(fileName);
    readFile(fileName);
    rowCount--; //The filestream reads one line extra, which we don't want
    cursor = 0;
    jumpsCompleted = 0;
    challengeNr = nr;
}

int Jumps::testn() {
    for (int i = 0; i < rowCount; i++) {
        std::cout << values[i] << "\t";
    }
    std::cout << "\n";
    return 27;
}

void Jumps::readFile(std::string fileName) {
    assert(!fileName.empty());
    values = new int[rowCount];

    std::ifstream fileStream(fileName);

    int i = 0;
    while (fileStream) {
        fileStream >> values[i];
        i++;
    }
}

int Jumps::countRows(std::string fileName) {
    int count(0);
    std::ifstream fileStream(fileName);

    std::string throwaway;
    
    while (fileStream) {
        count++;
        fileStream >> throwaway;
    }

    return count;
}

//sets new cursor location
void Jumps::jump() {
    //read value in cursor location
    int currentValue = values[cursor];
    //increment value in cursor location
    values[cursor] = values[cursor] + 1;
    //move cursor
    cursor += currentValue;
}

void Jumps::jump2() {
    int currentValue = values[cursor];
    if (currentValue >= 3) {
        values[cursor] = values[cursor] - 1;
    } else {
        values[cursor] = values[cursor] + 1;
    }

    cursor += currentValue;
}

//return amount of jumps required
int Jumps::jumpAll() {
    if (challengeNr == 1) {
        while (cursor >= 0 && cursor < rowCount) {
            jump();
            jumpsCompleted++;
        }
    } else if (challengeNr == 2) {
        while (cursor >= 0 && cursor < rowCount) {
            jump2();
            jumpsCompleted++;
        }
    }

    return jumpsCompleted;
}