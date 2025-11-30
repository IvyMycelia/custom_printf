# Custom `print()` for C90+

I was bored, so I made a custom print function in C without using any external libraries. I'm pretty proud of myself for this, even though it wasn't too tricky.

*I hate assembly so much.*

## Features

\- String-only support (for now)

\- **Escape Sequences** supported

\- One argument per call

## Usage

### Option 1:
1. Download `print.c` & `print.h`
2. Place `print.c` into your source directory
3. Place `print.h` into your include directory
4. Include the headers in your C file:
```c
#include "print.h"

int main() {
    print("Hello, World!\n");
    return 0;
}
```

### Option 2:
1. Download **print** package and place it somewhere accessible.
2. Include the headers in your C file:
    ```c
    #include "print.h"
    
    // Code..
    ```
3. Link against the static library while building:
    ```bash
    gcc main.c -I/path/to/print/include -L/path/to/print/lib -lrprint -o my_program
    ```


