#include <fstream>
#include <sstream>
#include <iostream>
#include <list>
#include <iomanip>

#define HASH_SUFFIX "17 31 73 47 23";

class Knot {
private:
    int* m_list;
    int m_listSize;
    std::string m_input;

    void getInput(std::string fileName);
    std::string parseInput(std::string input);
    void initializeList();
    void twist(int pos, int length);
    std::string denseHash();
    template< typename T >
    std::string int_to_hex(T i);

    void run();

public:
    Knot(std::string fileName, int listSize);
};