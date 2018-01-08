#include "firewall.h"

int main (int argc, char *argv[]) {
    Firewall firewall(argv[1]);
    firewall.run();

    return 0;
}