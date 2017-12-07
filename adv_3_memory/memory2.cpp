#include <iostream>
#include <cmath>

#define TARGET 325489
#define TARGET_TEST 100

struct Node {
    int x;
    int y;
    int d;
};

int main(){
    //location
    int x = 0;
    int y = 0;
    //radius
    int r = 0;
    //helper variable for node value
    int d = 1;
    //helper variable for node sum
    int sum = 0;
    //running value for the current position in the array
    int i = 0;

    //We store all the nodes in a single array and assume that we won't need more than 256 nodes
    Node nodes[256] = {};

    while (d < TARGET) {
        //calculate value of the next node
        d = 0;
        for(int a = 0; nodes[a].d != 0; a++){
            if (std::abs(nodes[a].x - x) <= 1 && std::abs(nodes[a].y - y) <= 1){
                d += nodes[a].d;
            }
        }

        d = (d > 0) ? d : 1;

        //add current node to the array
        Node n = {x, y, d};
        nodes[i] = n;
        //if we're in the bottom right corner increase the size of our square
        if (x == r && y == -r) {
            r++;
            x++;
        }
        //if we're on the right edge, move up until we're in the top right corner
        else if (x >= r && y < r) {
            y++;
        }
        //if we're on the top edge, move left until we're in the top left corner
        else if (y >= r && x > -r) {
             x--;
        }
        //if we're on the left edge, move down until we're in the bottom left corner
        else if (x <= -r && y > -r) {
            y--;
        }
        //if we're on the bottom edge, move right until we're in the bottom right corner
        else if (y <= -r && x < r) {
            x++;
        }

        i++;
    }
    
    for (int e = 0; nodes[e].d != 0; e++){
        std::cout << "Node " << e << ": x=" << nodes[e].x << ", y=" << nodes[e].y << ", d=" << nodes[e].d << "\n";
    }

    return 0;
}