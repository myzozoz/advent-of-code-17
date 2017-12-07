#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <sstream>


int main () {
    std::ifstream is("check.txt");
    std::string line;


    int input(0), sum(0);
    int numbers[256] = {0}; //We assume that no row will have more than 256 items
    int a;
    while(std::getline(is, line)){
        
        std::stringstream stream(line);

        //read line into array
        a = 0;
        while (stream >> input){
            numbers[a] = input;
            a++;
        }

        //because performance _should not_ be an issue, the check will be done with lazy nested loops
        for (int i = 0; numbers[i]; i++){
            for (int e = 0; numbers[e]; e++){
                if (numbers[i] > numbers[e] && numbers[i] % numbers[e] == 0) {
                    sum += numbers[i] / numbers[e];
                }
            }
        }

        //reset array to default
        for (int i = 0; i < sizeof(numbers)/sizeof(int); i++){
            numbers[i] = 0;
        }
    }

    std::cout << "Checksum: " << sum << "\n";
   
}
