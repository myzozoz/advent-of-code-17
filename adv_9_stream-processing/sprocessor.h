#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

class SProcessor {
private:
    std::string m_input;
    int garbageCount;

    void readInput(std::string fileName);
    std::string removeGarbage(std::string input);
    int countScore(std::string input);

    void run();

public:
    SProcessor(std::string fileName);
};