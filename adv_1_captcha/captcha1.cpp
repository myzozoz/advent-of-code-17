#include <iostream>
#include <string>
#include <fstream>

int getFileLength(std::ifstream stream);

int main () {
    std::ifstream fileStream ("cap.txt");

        

    if (fileStream){
        //Get the length of the file
        fileStream.seekg(0, fileStream.end);
        int length = fileStream.tellg();
        fileStream.seekg(0, fileStream.beg);

        char * captcha = new char[length];
        fileStream.read(captcha, length);
    

        if (fileStream) {
            //This is where the magic happens
            int sum = 0;
            for (int i = 1; i < length; i++) {
                if (captcha[i] == captcha[(i + length / 2) % length]){
                    sum += captcha[i] - 48;
                }
            }

            /* if (captcha[0] == captcha[length-1]){
                sum += captcha[0] - 48;
            }*/

            std::cout << "Sum: " << sum << "\n" << "length: " << length << "\n";

        } else {
            std::cout<<"There was a problem with reading the file";
        }
        delete[] captcha;
    }
    return 0;
}