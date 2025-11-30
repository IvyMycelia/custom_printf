//
// Created by Ivy on 11/29/25.
//

#if defined(__x86_64__)
    #define SYS_WRITE()                     \
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

    #define SYS_EXIT()                      \
        asm volatile (                      \
            "movq $0x2000001, %%rax\n"      \
            "movq $0, %%rdi\n"              \
            "syscall\n"                     \
            :                               \
            : "r"(c), "r"(l)                \
            : "%rax", "%rdi", "%rsi", "%rdx"\
        );

#elif defined(__aarch64__)
    #define SYS_WRITE()                 \
        asm volatile (                  \
            "mov x0, #1\n"              \
            "mov x1, %0\n"              \
            "mov x2, %1\n"              \
            "ldr x16, =0x2000004\n"     \
            "svc #0\n"                  \
            :                           \
            : "r"(c), "r"(l)            \
            : "x0", "x1", "x2", "x16"   \
        );

    #define SYS_EXIT()              \
        asm volatile (              \
            "mov x0, #0\n"          \
            "ldr x16, =0x2000001\n" \
            "svc #0"                \
            :                       \
            :                       \
            : "x0", "x16"           \
        );

#else
    #error "Unrecognized OS Architecture"
#endif

int print(char *c) {
    // Measure length
    unsigned long l = 0;
    char *p = c;
    while (*p != '\0') l++;

    // Write
    SYS_WRITE();

    // Exit
    SYS_EXIT();

    return 0;
}
