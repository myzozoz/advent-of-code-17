#pragma once

#include <unordered_map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <list>
#include <utility>
#include <deque>

using namespace std;

class Plumber{
private:
    unordered_map<int, list<int>> m_progMap;
    unordered_map<int, int> m_colorMap;

    void readFile(string fileName);
    void parseLine(string line);
    int countConnected(int rootNode);
    int countGroups();

public:
    Plumber(string fileName);
    void run();
};