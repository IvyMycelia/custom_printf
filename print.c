//
// Created by Ivy on 11/29/25.
//

void print(char *c) {
    unsigned long l = 0;
    char *p;
    for (p = c; *p; p++) l++;

    #if defined(__x86_64__)
    asm volatile (
        "movq $0x2000004, %%rax\n"
        "movq $1, %%rdi\n"
        "movq %0, %%rsi\n"
        "movq %1, %%rdx\n"
        "syscall\n"
        :
        : "r"(c), "r"(l)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );
    #elif defined(__aarch64__)
        register const char *x1 asm("x1") = c;
        register unsigned long x2 asm("x2") = l;
        register unsigned long x0 asm("x0") = 1;
        register unsigned long x16 asm("x16") = 0x2000004;
        asm volatile("svc #0" : : "r"(x0), "r"(x1), "r"(x2), "r"(x16) : "memory");
    #else
        #error "Unsupported architecture"
    #endif
}