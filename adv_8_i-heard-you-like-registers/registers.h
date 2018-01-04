#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <utility>
#include <climits>

class Registers {
private:
    std::vector<std::vector<std::string>> m_input;
    int m_rowc;
    int highestVal;
    std::unordered_map<std::string, int> m_regMap;

    void readFile(std::string fileName);
    void countRows(std::string fileName);
    bool fileExists(std::string fileName);
    void findRegisters();
    void runCommands();
    int findHighest();
    
    bool eval(std::string reg, std::string op, int val);
    void execute(std::string reg, std::string cmd, int val);

    void run();

public:
    Registers(std::string fileName);
    void printInput();
    void printRegs();
    void printCurrentHighest();
    void printAllTimeHighest();
};