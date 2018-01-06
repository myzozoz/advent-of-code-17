#include "sprocessor.h"

SProcessor::SProcessor(std::string fileName) {
    readInput(fileName);
    garbageCount = 0;
    run();
}

void SProcessor::readInput(std::string fileName) {
    std::ifstream fileStream(fileName);

    if (!fileStream) {
        std::cerr << "File could not be opened!\n";
        exit(1);
    }

    //we assume there are no whitespaces in the input
    fileStream >> m_input;
}

void SProcessor::run() {
    //parse input
    std::string parsedInput = removeGarbage(m_input);
    std::cout << m_input << "\n";
    std::cout << parsedInput << "\n";
    //analyze parsed input
    int score = countScore(parsedInput);
    std::cout << "Score: " << score << "\n";
    std::cout << "Amount of garbage removed: " << garbageCount << "\n";
}

std::string SProcessor::removeGarbage(std::string input) {
    int state = 0; //states: 0=garbage not found, 1=garbage found
    int garbageStart(0), garbageEnd(0);
    for (std::string::size_type i = 0; i < input.size(); i++) {
        if (input[i] == '<' && state == 0) {
            state = 1;
            garbageStart = i;
        } else if (input[i] == '!') {
            i++;
        } else if (input[i] == '>') {
            garbageEnd = i;
            break;
        } else if (state == 1) {
            garbageCount++;
        }
    }

    if (state != 0) {
        std::cout << "garbage start-end: " << garbageStart << "-" << garbageEnd << "\n";
        input.erase(garbageStart, garbageEnd - garbageStart + 1);
        input = removeGarbage(input);
    }

    return input;
}

int SProcessor::countScore(std::string input) {
    int score = 0;
    int level = 0;
    
    for (std::string::size_type i = 0; i < input.size(); i++) {
        if (input[i] == '{'){
            level++;
        } else if (input[i] == '}'){
            score +=level;
            level--;
        }
    }

    return score;
}