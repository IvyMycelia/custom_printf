//
// Created by Ivy on 11/29/25.
//

int print(char *c) {
    // Measure length
    unsigned long l = 0;
    char *p = c;
    while (*p != '\0') l++;

    // Write
    #if defined(__x86_64__)
        // x86_64
        asm volatile (
                "movq $0x2000004, %%rax\n"  // syscall number for write
                "movq $1, %%rdi\n"          // stdout
                "movq %0, %%rsi\n"          // buffer (content)
                "movq %1, %%rdx\n"          // length of content
                "syscall\n"

                "movq $0x2000001, %%rax\n"   // syscall number for exit
                "movq $0, %%rdi\n"           // exit code '0'
                "syscall\n"
                :
                : "r"(c), "r"(l)
                : "%rax", "%rdi", "%rsi", "%rdx"
                );
    #elif defined(__aarch64__)
        // ARM
        asm volatile (
                "mov x0, #1\n"          // stdout
                "mov x1, %0\n"          // buffer (content)
                "mov x2, %1\n"          // length of content
                "ldr x16, =0x2000004\n" // syscall number for write
                "svc #0\n"
                :
                : "r"(c), "r"(l)
                : "x0", "x1", "x2", "x16"
        );

        // Exit
        asm volatile (
                "mov x0, #0\n"          // exit code '0'
                "ldr x16, =0x2000001\n" // syscall number for exit
                "svc #0"
                :
                :
                : "x0", "x16"
        );
    #else
    #error "Unrecognized OS Architecture"
    #endif
    return 0;
}
