#include "plumber.h"

Plumber::Plumber(string fileName) {
    readFile(fileName);
}

void Plumber::run() {
    std::cout << "Total connections: " << countConnected(0) << "\n";
    std::cout << "Amount of groups: " << countGroups() << "\n";
}

int Plumber::countGroups() {
    //re-initialize colors to white
    for (pair<int, int> c : m_colorMap) {
        m_colorMap[c.first] = 0;
    }
    
    int groups = 0;
    for (pair<int, list<int>> n : m_progMap) {
        if (m_colorMap[n.first] == 0) {
            countConnected(n.first);
            groups++;
        }
    }
    return groups;
}

int Plumber::countConnected(int rootNode) {
    m_colorMap[rootNode] = 1;
    deque<int> deque(1,rootNode);

    int n;
    while (!deque.empty()) {
        n = deque[0];
        deque.pop_front();
        for (int i : m_progMap[n]) {
            if (m_colorMap[i] == 0){
                m_colorMap[i] = 1;
                deque.push_back(i);
            }
        }
        m_colorMap[n] = 2;
    }

    int found = 0;
    for (pair<int, int> c: m_colorMap) {
        if (c.second == 2) {
            found++;
        }
    }

    return found;
}

void Plumber::readFile(string fileName) {
    ifstream fileStream(fileName);

    if (!fileStream){
        cout << "File could not be opened.";
        exit(1);
    }

    string line;
    while (getline(fileStream, line)) {
        parseLine(line);
    }
}

void Plumber::parseLine(string line) {
    stringstream lineStream(line);
    string word;
    int progId;
    list<int> connections;
    //first word in line is the current prog
    lineStream >> word;
    progId = stoi(word);
    //second word is the arrows
    lineStream >> word;
    //rest of the words are connections (might have comma appended)
    while (lineStream >> word) {
        if (word.find(",") != string::npos) {
            word.erase(word.find(","),1);
        }
        connections.push_back(stoi(word));
    }

    m_progMap[progId] = connections;
    m_colorMap[progId] = 0;
}