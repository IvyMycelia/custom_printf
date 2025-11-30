/*
 * `main.c`
 * This is here just for debugging purposes.
 * If you want to use `print` itself, you only
 * have to download `print.c` and `print.h`.
 */

#include "print.h"

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    int i; for (i = 1; i < argc; i++) print(argv[i]);
    return 0;
}