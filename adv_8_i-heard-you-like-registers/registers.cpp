#include "registers.h"

Registers::Registers(std::string fileName) {
    if (!fileExists(fileName)){
        std::cerr << "File not found.\n";
        exit(1);
    }
    countRows(fileName);
    readFile(fileName);

    run();
}

void Registers::run() {
    findRegisters();
    runCommands();

    printCurrentHighest();
    printAllTimeHighest();
}

int Registers::findHighest() {
    int max = INT_MIN;
    for (std::pair<std::string, int> reg : m_regMap) {
        if (reg.second > max) {
            max = reg.second;
        }
        if (reg.second > highestVal) {
            highestVal = reg.second;
        }
    }
    return max;
}

void Registers::runCommands() {
    for (std::vector<std::string> line : m_input) {
        if (eval(line[4], line[5], stoi(line[6]))) {
            execute(line[0], line[1], stoi(line[2]));
            findHighest();
        }
    }
}

bool Registers::eval(std::string reg, std::string op, int val) {
    if (op == "<") {
        return (m_regMap[reg] < val);
    } else if (op == ">") {
        return (m_regMap[reg] > val);
    } else if (op == "==") {
        return (m_regMap[reg] == val);
    } else if (op == "!=") {
        return (m_regMap[reg] != val);
    } else if (op == "<=") {
        return (m_regMap[reg] <= val);
    } else if (op == ">=") {
        return (m_regMap[reg] >= val);
    }
}

void Registers::execute(std::string reg, std::string cmd, int val) {
    if (cmd == "inc") {
        m_regMap[reg] += val;
    } else if (cmd == "dec") {
        m_regMap[reg] -= val;
    }
}

void Registers::findRegisters() {
    for (std::vector<std::string> v : m_input) {
        m_regMap[v[0]] = 0;
    }
}

void Registers::printInput() {
    for(std::vector<std::string> v : m_input) {
        for (std::string s : v) {
            std::cout << s << " ";
        }
        std::cout << "\n";
    }
}

void Registers::readFile(std::string fileName) {
    std::ifstream fileStream(fileName);

    m_input.resize(m_rowc);

    std::string line;
    std::string word;
    int linec = 0;
    while (std::getline(fileStream, line)) {
        std::stringstream lineStream(line);
        m_input.at(linec).resize(7);
        for (int i = 0; lineStream >> word; i++) {
            m_input[linec][i] = word;
        }
        linec++;
    }
}

void Registers::countRows(std::string fileName) {
    std::ifstream fileStream(fileName);
    int i = 0;
    std::string dummy;
    while(std::getline(fileStream, dummy)){
        i++;
    }
    m_rowc = i;
}

bool Registers::fileExists(std::string fileName) {
    std::ifstream fileStream(fileName);
    if (!fileStream) {
        return false;
    }
    return true;
}

void Registers::printRegs() {
    for (std::pair<std::string, int> reg : m_regMap) {
        std::cout << "Register/value: " << reg.first << "/" <<  reg.second << "\n";
    }
}

void Registers::printCurrentHighest() {
    std::cout << "Highest register value: " << findHighest() << "\n";
}

void Registers::printAllTimeHighest() {
    std::cout << "All time highest value: " << highestVal << "\n";
}