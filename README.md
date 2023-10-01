# ft_printf - A Printf Implementation @42 Málaga

## Introduction

`ft_printf` is a custom C library that mimics the functionality of the standard C `printf` function. It supports a variety of data types and format specifiers including integers, strings, characters, hexadecimal and pointer representation.

## Contents

```
- inc/
    - ft_printf.h
- src/
    - ft_auxiliary.c
    - ft_parse_chars.c
    - ft_parse_nums.c
    - ft_printf.c
```

## Dependencies

- Standard C Libraries
- gcc compiler
- make

## Features

- Parses `%c`, `%s`, `%d`, `%i`, `%x`, `%X`, `%p` and `%u` format specifiers.
- Efficiently uses variadic functions to handle a variable number of arguments.
- Writes to standard output.

## How to Use

1. Clone the repository.
2. Run `make` to compile the code.
3. Include `ft_printf.h` in your C files.
4. Link against the compiled library when building your main application.

### Example
```bash
gcc -o your_program your_source_file.c -I./path_to_ft_printf/inc -L./path_to_ft_printf -lftprintf
```

## Functions

- `int ft_printf(char const *str, ...)`: The main printf function.

### Supported Format Specifiers

- `%c`: Character.
- `%s`: String.
- `%d` & `%i`: Decimal integer.
- `%x`: Unsigned hexadecimal integer (lowercase).
- `%X`: Unsigned hexadecimal integer (uppercase).
- `%p`: Pointer.
- `%u`: Unsigned decimal integer.
- `%%`: Percent character.
