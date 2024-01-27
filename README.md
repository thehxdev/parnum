# Parnum

A C99 compatible single header library for parsing numbers from string literals with no external dependencies.



## Status

- [x] Parse single integer values
- [x] Parse single floating point numbers
- [ ] Parse all integers as a heap allocated array
- [ ] Parse all floats as a heap allocated array



## Usage
Just include `parnum.h` then compile and link `parnum.c` with your project.



## Public API
Public API of Parnum library.

### `long parnum_parse_int(const char *s)`
This function recives a constant character pointer (`const char *s`) and parses a single integer value (the first one).
If no integer value found in the string, returns 0.


### `double parnum_parse_float(const char *s)`
This function recives a constant character pointer (`const char *s`) and parses a single float value (the first one).
If no float value found in the string, returns `0.0`.



## Example

```c
#include "parnum.h"

int main(void) {
    long x;
    double y;

    x = parnum_parse_int("Hello1234World!"); // x will be 1234
    y = parnum_parse_float("Testin the 181.21 double parser"); // y will be 181.21

    y = parnum_parse_float("(-PI) = -3.14"); // y will be -3.14
    x = parnum_parse_int("temperature is -10 deree"); // x will be -10

    return 0;
}
```


## Nix
If you are a NixOS user or you have `nix` package manager installed, you can use this section to create a
development environment for C language.

> [!NOTE]
> Make sure that `nix-command` and `flakes` are enabled. (Search for enabling nix experimental features)

Enter development environment:
```bash
nix develop
```

This will make a temporarily shell with `gcc`, `gnumake`, `gdb` and `valgrind` packages available.
It also downloads `ccls` package (with some LLVM libraries) as language server program (I use this in neovim).
