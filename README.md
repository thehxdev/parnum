# Parnum

A C99 compatible single header library for parsing numbers from string literals with no external dependencies.


## Status

- [x] Parse single integer values
- [ ] Parse single floating point numbers
- [ ] Parse all integers as a heap allocated array
- [ ] Parse all floats as a heap allocated array


## Usage
Just include `parnum.h` then compile and link `parnum.c` with your project.


## Public API
Public API of Parnum library.

### `int parnum_parse_int(const char *s)`

This function recives a constant character pointer (`const char *s`) and parses a single integer value (the first one).
If no integer value found in the string, returns 0.


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
