/*
 * `main.c`
 * This is here just for debugging purposes.
 * If you want to use `print` itself, you only
 * have to download `print.c` and `print.h`.
 */

#include "print.h"

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    int i; for (i = 1; i < argc; i++) {
        char buff[1028];
        int j = 0;
        char *p = argv[i];

        while (*p) {
            if (*p == '\\') {
                p++;
                if (*p == '\0') break;
                switch (*p) {
                    case 'n':
                        buff[j++] = '\n'; break;
                    case 't':
                        buff[j++] = '\t'; break;
                    default:
                        buff[j++] = *p; break;
                }
                p++;
            } else {
                buff[j++] = *p;
                p++;
            }
        }

        buff[j] = '\0';
        print(buff);
        if (i < argc - 1) print(" ");
    }
    print("\n");
    return 0;
}