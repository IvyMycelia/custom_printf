# Custom `print()` for C90+

I was bored, so I made a custom print function in C without using any external libraries. I'm pretty proud of myself for this, even though it wasn't too tricky.

*I hate assembly so much.*

---

## Features

\- String-only support (for now)

\- **Escape Sequences** supported

\- One argument per call

---

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
   
---

## Frequently Asked Questions

### How To Use This On Windows?

**Answer:** 
   
**Step One:** Download a [Linux Distro](https://www.linux.org/pages/download/)

**Step Two:** Refer to [Usage](#usage)

### Will Windows Support Be Added?

**Answer:** No, windows support will not be added. Windows changes their syscall codes every version update. I'd have to use an external source file or library for this to work (which is against the project).

### Does This Work On Linux?

**Answer:** Yes, this code should run on many Linux distros. If you have a specific issue, please open a [Pull Request](https://github.com/IvyMycelia/custom_printf/pulls)!

### What About macOS?

**Answer:** It should, I made this on my Macbook.