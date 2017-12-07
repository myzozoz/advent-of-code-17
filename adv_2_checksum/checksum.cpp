#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <sstream>

int main () {
    std::ifstream is("check.txt");
    std::string line;


    int i(0), sum(0), max, min;

    while(std::getline(is, line)){
        max = 0;
        min = INT_MAX;

        std::stringstream stream(line);

        while (stream >> i){
            if (i < min)
                min = i;
            if (i > max)
                max = i;
        }
        sum += max - min;
    }

    std::cout << "Sum: " << sum << "\n";

    

    //get file length
   
}