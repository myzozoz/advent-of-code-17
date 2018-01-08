#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>  
#include <list>
#include <vector>

class Hexed {
private:
    std::list<std::string> m_steps;
    //This vector contains the amounts of steps taken in each direction
    //0=n, 1=ne, 2=se, 3=s, 4=sw, 5=nw
    int * m_directions;
    int m_maxDist;

    void readFile(std::string fileName);
    void parseSteps(std::string input);
    void countSteps();
    int countDistance();
    void reduce();

public:
    Hexed(std::string fileName);
    void run();
};