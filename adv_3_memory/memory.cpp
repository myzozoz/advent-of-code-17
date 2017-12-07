#include <iostream>
#include <climits>
#include <cmath>

#define PUZZLE_INPUT 325489
#define TEST_INPUT_1 1
#define TEST_INPUT_2 12
#define TEST_INPUT_3 23
#define TEST_INPUT_4 1024

int main (){
    double exp(2.0), base(1.0), prod(.0); 

    int input = TEST_INPUT_1;

    while (prod < input) {
        prod = pow(base, exp);
        base += 2;
    }

    double finalPow = pow(base-4, exp);
    double lastFullSquare   = ((base - 4 < 0) ? 0 : finalPow);
    double maxDigitsInFinalSquare = prod - lastFullSquare;
    double actualDigitsInFinalSquare = input - lastFullSquare;
    if (input != 1) {
        double sideLength = maxDigitsInFinalSquare / 4;
        std::cout << "Side length: " << sideLength << "\n";   

        //Make side independant
        double sideIndependant = (int)actualDigitsInFinalSquare % (int)sideLength;
        std::cout << "Side independant location: " << sideIndependant << "\n";


        double locationOnEdge = sideLength / 2.0 - sideIndependant;
        double distanceOnEdge = (locationOnEdge < 0) ? std::abs(locationOnEdge) : locationOnEdge;
        double manhattanDistanceFromCentre = (sideLength / 2) + distanceOnEdge;
    
    std::cout << "Distance on Edge: " << distanceOnEdge << "\n";
    std::cout << "Manhattan distance from centre: " << manhattanDistanceFromCentre << "\n\n"; 
    } else {
        std::cout << "Distance on Edge: 0\n";
        std::cout << "Manhattan distance from centre: 0 \n\n";
    }
    std::cout << "Number we are looking for: " << input << "\n\n";

    std::cout << "Total digits inside last full square: " << lastFullSquare << "\n";
    std::cout << "Max digits in final square: " << maxDigitsInFinalSquare << "\n";
    std::cout << "Max digits total (with final square): " << prod << "\n";
    std::cout << "Actual digits in final square: " << actualDigitsInFinalSquare << "\n";
}