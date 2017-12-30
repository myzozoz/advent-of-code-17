#pragma once

#include <string>
#include <fstream>
#include <cassert>
#include <iostream>

class Jumps {
private:
    int* values;
    int rowCount;
    int cursor;
    int jumpsCompleted;
    int challengeNr;

    void readFile(std::string fileName);
    int countRows(std::string fileName);
    void jump();
    void jump2();

public:
    Jumps(std::string fileName, int nr);
    int testn();
    int jumpAll();
};