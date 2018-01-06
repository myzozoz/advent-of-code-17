#include "knot.h"

Knot::Knot(std::string fileName, int listSize) {
    m_listSize = listSize;
    m_list = new int[listSize];
    initializeList();

    getInput(fileName);

    run();
}

void Knot::run() {
    int length{0}, pos{0}, skip{0};
    
    for (int i = 0; i < 64; i++) {
        std::stringstream sstream(m_input);

        while (sstream >> length) {
            //twist
            twist(pos, length);
            //move position length + skip size
            pos = (pos + length + skip) % m_listSize;
            //increment skip size
            skip++;
        }
    }

    std::cout << "Hash: "<< denseHash() << "\n";

    std::cout << "\n";
}

std::string Knot::denseHash() {
    int blocks[16];
    int block{0},bitwise_xor{0};
    for (int i = 0; i < m_listSize; i++) {
        bitwise_xor = bitwise_xor ^ m_list[i];
        if (i % 16 == 15) {
            blocks[block] = (int)bitwise_xor;
            bitwise_xor = 0;
            block++;
        }
    }
    std::string hash = "";
    for (int i = 0; i < 16; i++) {
        hash += int_to_hex(blocks[i]);
    }

    return hash;
}

template< typename T >
std::string Knot::int_to_hex( T i )
{
  std::stringstream stream;
  stream << std::setfill ('0') << std::setw(2) 
         << std::hex << i;
  return stream.str();
}

void Knot::initializeList() {
    for (int i = 0; i < m_listSize; i++) {
        m_list[i] = i;
    }
}

void Knot::twist(int pos, int length) {
    int* sublist = new int[length];
    for (int i = 0; i < length; i++) {
        sublist[i] = m_list[(pos + i) % m_listSize];
    }

    for (int i = 0; i < length; i++) {
        m_list[(pos + i) % m_listSize] = sublist[length - (i + 1)];
    }

    delete[] sublist;
}

void Knot::getInput(std::string fileName) {
    std::ifstream fileStream(fileName);
    std::string rawInput;

    std::getline(fileStream, rawInput);
    m_input = parseInput(rawInput);
}

std::string Knot::parseInput(std::string input) {
    std::string parsedInput = "";
    for (char& c : input) {
        parsedInput += std::to_string((int)c) + " ";
    }

    parsedInput += HASH_SUFFIX;
    return parsedInput;
}