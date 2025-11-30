//
// Created by Ivy on 11/29/25.
//

#if defined(__x86_64__)
    #define SYS_WRITE(c, l)                 \
        asm volatile (                      \
            "movq $0x2000004, %%rax\n"      \
            "movq $1, %%rdi\n"              \
            "movq %0, %%rsi\n"              \
            "movq %1, %%rdx\n"              \
            "syscall\n"                     \
            :                               \
            : "r"(c), "r"(l)                \
            : "%rax", "%rdi", "%rsi", "%rdx"\
        );
#elif defined(__aarch64__)
#define SYS_WRITE(c, l)                          \
    do {                                         \
        const char *buf = (c);                   \
        unsigned long len = (l);                 \
        register unsigned long x0 asm("x0") = 1; /* stdout */ \
        register const char *x1 asm("x1") = buf;           \
        register unsigned long x2 asm("x2") = len;         \
        register unsigned long x16 asm("x16") = 0x2000004; \
        asm volatile("svc #0" : : "r"(x0),"r"(x1),"r"(x2),"r"(x16) : "memory"); \
    } while(0)
#else
    #error "Unrecognized OS Architecture"
#endif

int print(char *c) {
    // Measure length
    unsigned long l = 0;
    char *p;
    for (p = c; *p; p++) l++;

    // Write
    SYS_WRITE(c, l);

    return 0;
}
