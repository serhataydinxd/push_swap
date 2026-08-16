*This project has been created as part of the 42 curriculum by seraydin.*

# ft_printf

## Description

`ft_printf` is a simplified reimplementation of the standard C `printf` function.

The goal of the project is to learn how variadic functions work and how formatted output can be implemented using low-level C functions.

Supported conversions:

`%c` `%s` `%p` `%d` `%i` `%u` `%x` `%X` `%%`

The project builds a static library called `libftprintf.a`.

## Instructions

Compile the library with:

```bash
make
```

Other available commands:

```bash
make clean
make fclean
make re
```

Use it in another C program with:

```c
#include "ft_printf.h"
```

Then compile:

```bash
cc main.c -lftprintf (or libftprintf.a) -o program
```

## Algorithm and Data Structure

`ft_printf` reads the format string one character at a time.

Normal characters are printed directly. When `%` is found, the next character determines which helper function is called.

Arguments are accessed using `va_list`, `va_start`, `va_arg`, and `va_end` from `<stdarg.h>`.

Numbers are printed recursively. Decimal numbers use division and modulo by `10`, while hexadecimal numbers use base `16`.

Output is written directly using `write()` instead of first creating a complete output string. This keeps the implementation simple and avoids unnecessary dynamic memory allocation.

The overall complexity is approximately `O(n)`, where `n` represents the amount of input and output processed.

## Resources

References used during the project:

* `man 3 printf`
* `man 3 stdarg`
* `man 2 write`
* GNU Make documentation
* C documentation for variadic functions

### AI Usage

AI was used to help review the project structure and create the README documentation.

It was also used to help explain the use of `va_list`, recursive number conversion. The implementation itself was checked against the project source code.
