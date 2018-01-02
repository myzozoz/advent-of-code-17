#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <unordered_map>

class Banks {
private:
    int bankCount;
    int * banks;
    std::unordered_map<std::string, int> foundMap;

    void readFile(std::string fileName);
    void level();
    int findHighest();
    void distribute(int blocks, int start);
    std::string stringify();

public:
    Banks(std::string fileName, int bankCount);
    void testPrint();
    int solve();
};