//
// Created by Ivy on 11/29/25.
//

static void print_char(char c) {
#if defined(__x86_64__)
    asm volatile (
        "movq $0x2000004, %%rax\n"
        "movq $1, %%rdi\n"
        "movq %0, %%rsi\n"
        "movq %1, %%rdx\n"
        "syscall\n"
        :
        : "r"(&c)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );
#elif defined(__aarch64__)
    register const char *x1 asm("x1") = &c;
    register unsigned long x2 asm("x2") = 1;
    register unsigned long x0 asm("x0") = 1;
    register unsigned long x16 asm("x16") = 0x2000004;
    asm volatile("svc #0" : : "r"(x0), "r"(x1), "r"(x2), "r"(x16) : "memory");
#else
#error "Unsupported architecture"
#endif
}

void print(char *c) {
    char *p = c;
    while (*p) {
        if (*p == '\\') {
            p++;
            if (*p == '\0') break;
            switch (*p) {
                case 'n':   print_char('\n');   break;
                case 't':   print_char('\t');   break;
                case '\\':  print_char('\\');   break;
                case '"':   print_char('"');    break;
                case 'r':   print_char('\r');   break;
                case '0':   print_char('\0');   break;
                default:    print_char(*p);     break;
            }
            p++;
        } else {
            print_char(*p);
            p++;
        }
    }
}