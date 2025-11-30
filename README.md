# Custom `print()` for C90+

I was bored, so I made a custom print function in C without using any external libraries. I'm pretty proud of myself for this, even though it wasn't too tricky.

*I hate assembly so much.*

### Usage:
1. Download `print.c` & `print.h`
2. Use in your C Project:
```c
#include "print.h"

int main() {
    print("Hello, World!\n");
    return 0;
}
```