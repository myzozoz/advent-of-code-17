#include "firewall.h"

Firewall::Firewall(string fileName) {
    m_maxDepth = 0;
    readFile(fileName);
}

void Firewall::run() {
    int delay = 0;
    int severity = countSeverity(delay);
    cout << "Severity without delay: " << severity << "\n";

    while (severity != 0 || hit(0, delay)) {
        delay++;
        severity = countSeverity(delay);
    }
    
    cout << "Delay needed: " << delay << "\n";
}

int Firewall::countSeverity(int delay) {
    int severity = 0;
    //run until past the last scanner
    for (pair<int, int> scanner : m_scanners) {
        //if there's a hit at the depth of the scanner
        if (hit(scanner.first, delay)) {
            severity += scanner.first * scanner.second;
        }
    }
    return severity;
}

bool Firewall::hit(int depth, int delay) {
    //it's a hit if time elapsed % amount of positions for the scanner == 0
    //elapsed time is depth + delay
    //the amount of positions is calculated with 
    //posN = range * 2 - 2, range > 1; posN = range range <= 1
    int range{m_scanners[depth]};
    int posN;
    if (range == 1) {
        posN = 1;
    } else {
        posN = range * 2 - 2;
    }
    
    if ((depth + delay) % posN == 0) {
        return true;
    }
    return false;
}

void Firewall::readFile(string fileName) {
    ifstream fileStream(fileName);

    if (!fileStream) {
        cerr << "File could not be opened\n";
        exit(1);
    }

    string line;
    while (getline(fileStream,line)) {
        parseLine(line);
    }
}

void Firewall::parseLine(string line) {
    stringstream lineStream(line);
    string word;

    lineStream >> word;
    word.erase(word.find(":", 1));
    int depth = stoi(word);
    if (depth > m_maxDepth) {
        m_maxDepth = depth;
    }

    lineStream >> word;
    int range = stoi(word);

    m_scanners[depth] = range;
}