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
