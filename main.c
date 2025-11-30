#include "print.h"

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    return print(argv[1]);
}

/*
 * RETURN CODES:
 *  -1 —> INVALID ARCHITECTURE
 *  0  —> SUCCESS
 *  1  —> NO PRINT INPUT
*/