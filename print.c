//
// Created by Ivy on 11/29/25.
//

// print.c
#include "print.h"

static inline void sys_write_char(char c) {
#if defined(__x86_64__) && defined(__APPLE__)
    // macOS x86_64
    asm volatile (
        "movq $0x2000004, %%rax\n"
        "movq $1, %%rdi\n"
        "movq %0, %%rsi\n"
        "movq $1, %%rdx\n"
        "syscall\n"
        :
        : "r"(&c)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );
#elif defined(__x86_64__) && defined(__linux__)
    // Linux x86_64
    asm volatile (
        "movq $1, %%rax\n"
        "movq $1, %%rdi\n"
        "movq %0, %%rsi\n"
        "movq $1, %%rdx\n"
        "syscall\n"
        :
        : "r"(&c)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );
#elif defined(__aarch64__) && defined(__APPLE__)
    // macOS ARM64
    register const char *x1 asm("x1") = &c;
    register unsigned long x0 asm("x0") = 1;
    register unsigned long x2 asm("x2") = 1;
    register unsigned long x16 asm("x16") = 0x2000004;
    asm volatile("svc #0" : : "r"(x0), "r"(x1), "r"(x2), "r"(x16) : "memory");
#elif defined(__aarch64__) && defined(__linux__)
    // Linux ARM64
    register const char *x1 asm("x1") = &c;
    register unsigned long x0 asm("x0") = 1;
    register unsigned long x2 asm("x2") = 1;
    register unsigned long x8 asm("x8") = 64; // sys_write in Linux ARM64
    asm volatile("svc #0" : : "r"(x0), "r"(x1), "r"(x2), "r"(x8) : "memory");
#else
    #error "Unsupported architecture/OS"
#endif
}

void print_char(char c) {
    sys_write_char(c);
}

void print(const char *c) {
    while (*c) {
        if (*c == '\\') {
            c++;
            if (*c == '\0') break;
            switch (*c) {
                case 'n': print_char('\n'); break;
                case 't': print_char('\t'); break;
                case '\\': print_char('\\'); break;
                case '"': print_char('"'); break;
                case 'r': print_char('\r'); break;
                default: print_char(*c); break;
            }
            c++;
        } else {
            print_char(*c++);
        }
    }
}
