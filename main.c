#include "print.h"

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;

    return print(argv[1]);

    // return 0;
}