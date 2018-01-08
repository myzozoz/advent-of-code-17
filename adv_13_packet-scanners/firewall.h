#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <iostream>

using namespace std;

class Firewall{
private:
    unordered_map<int, int> m_scanners;
    int m_maxDepth;

    void readFile(string fileName);
    void parseLine(string line);
    bool hit(int depth, int delay);
    int countSeverity(int delay);

public:
    Firewall(string fileName);
    void run();
};