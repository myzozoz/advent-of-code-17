#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <algorithm>

#define INPUT "input.txt"

bool is_anagram(std::string s1, std::string s2) {
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    return s1==s2;
}

int main () {
    std::ifstream input(INPUT);

    //Make sure the file is found
    if (!input) {
        std::cerr << "Could not open file " << INPUT << "\n";
        exit(1);
    }

    int invalidpwcount = 0;
    int validpwcount = 0;
    int equalwordcount = 0;
    int linenr = 1;
    int found = 0; 

    //Check one line at a time
    while (input) {
        std::string line;
        std::getline(input, line);
        std::stringstream linestream1(line);
        found = 0;
        
        
        //Check the words one at a time
        while (linestream1 && !found) {
            equalwordcount = 0;
            std::string searchable;
            linestream1 >> searchable;
            std::stringstream linestream2(line);

            //Search for every string on every line (nested loops ftw)
            while (linestream2) {
                std::string comparable;
                linestream2 >> comparable;

                //insert check for anagram instead
                if (is_anagram(comparable, searchable)) {
                    equalwordcount++;
                }
            }

            if (equalwordcount > 1) {
                invalidpwcount++;
                found = 1;
                break;
            }
        }

        if (!found && !line.empty()) {
            validpwcount++;
        }
       

        linenr++;
        //std::cout << line << "\n";
    }

    std::cout << "invalid passwords: " << invalidpwcount << "\n";
    std::cout << "valid passwords: " << validpwcount << "\n";


    return 0;
}

