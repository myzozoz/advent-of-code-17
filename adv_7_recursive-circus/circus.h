#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include <utility>
#include <unordered_map>

#include "prog.h"

class Circus {
private:
    std::unordered_map<std::string, Prog*> progMap;
    std::string m_fileName;
    std::string m_root;
    std::string m_problemChild;

    void lineHandler(std::string line);
    int parseWeight(std::string weight);
    std::string parseChild(std::string child);
    void travel(std::string parent, int child_weight);
    std::string faultyChild(std::string parent);
    std::string faultySubtree(std::string parent);
    bool faultExists(std::string parent);

    void firstPass();
    void secondPass();
    std::string thirdPass();
    void fourthPass();
    std::string fifthPass();

    void testPrint();

public:
    Circus(std::string fileName);
    std::string bottom();
    std::string unbalanced();
    int desiredWeight();
};