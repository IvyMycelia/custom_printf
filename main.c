#include "print.h"

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    int i; for (i = 1; i < argc; i++) print(argv[i]);
    return 0;
}