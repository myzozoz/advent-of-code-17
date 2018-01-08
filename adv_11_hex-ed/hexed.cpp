#include "hexed.h"

Hexed::Hexed(std::string fileName) {
    readFile(fileName);
    m_directions = new int[6] {};
    m_maxDist = 0;
}

void Hexed::run() {
    //count how many steps were taken in each direction;
    countSteps();
    countDistance();

    std::cout << "Distance: " << countDistance() << "\n";
    std::cout << "Max distance: " << m_maxDist << "\n";

}

void Hexed::reduce() {
    int counter = 0;
    for (int i = 0; counter != 6; i++) {
        if(m_directions[i % 6] > 0 && m_directions[(i+2) % 6] > 0) {
            int reduction = std::min(m_directions[i % 6], m_directions[(i+2) % 6]);

            m_directions[i % 6] -= reduction;
            m_directions[(i+2) % 6] -= reduction;
            m_directions[(i+1) % 6] += reduction;
            
            counter = 0;
        }
        counter++;
    }
}

int Hexed::countDistance() {
    //we can apply the principles of manhattan distance in the hex grid
    //the only difference is that ne + nw = n, so we can remove one step
    //same with se + sw = s, n + se = ne ...
    reduce();
    int distance = 0;
    for (int i = 0; i < 6; i++) {
        distance += m_directions[i];
    }
    return distance;
}

void Hexed::countSteps() {
    for (std::string s : m_steps) {
        if (s == "n")
            m_directions[0] += 1;
        else if (s == "ne")
            m_directions[1] += 1;
        else if (s == "se")
            m_directions[2] += 1;
        else if (s == "s")
            m_directions[3] += 1;
        else if (s == "sw")
            m_directions[4] += 1;
        else if (s == "nw") 
            m_directions[5] += 1;
        
        int dist = countDistance();
        if (dist > m_maxDist) {
            m_maxDist = dist;
        }
    }
}

void Hexed::readFile(std::string fileName) {
    std::ifstream fileStream(fileName);

    if (!fileStream) {
        std::cerr << "File could not be opened\n";
        exit(1);
    }

    std::string input;
    fileStream >> input;

    parseSteps(input);
}

void Hexed::parseSteps(std::string input) {
    std::string dir;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ',') {
            m_steps.push_back(dir);
            dir = "";
        } else {
            dir += input[i];
        }
    }
    m_steps.push_back(dir);
}