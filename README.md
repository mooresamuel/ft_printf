# ft_printf

A custom implementation of the `printf` function for 42 London projects, written in C. This implementation supports various format specifiers and flags, enabling formatted output for strings, characters, integers, unsigned integers, pointers, and hexadecimal values.

## Table of Contents
1. [Introduction](#introduction)
2. [Supported Format Specifiers](#supported-format-specifiers)
3. [Supported Flags](#supported-flags)
4. [Usage](#usage)
5. [Function Overview](#function-overview)
6. [Compilation and Testing](#compilation-and-testing)
7. [License](#license)

---

## Introduction
The `ft_printf` function replicates the behavior of the standard `printf` function, providing formatted output capabilities. This project was created as part of the curriculum at **42 London** and demonstrates proficiency in handling variable argument lists, parsing format strings, and applying formatting rules.

---

## Supported Format Specifiers

The `ft_printf` function supports the following format specifiers:

| Specifier | Description |
|-----------|-------------|
| `c`       | Outputs a single character. |
| `s`       | Outputs a string. |
| `p`       | Outputs a pointer address in hexadecimal format. |
| `d` or `i`| Outputs a signed decimal integer. |
| `u`       | Outputs an unsigned decimal integer. |
| `x`       | Outputs an unsigned hexadecimal integer (lowercase). |
| `X`       | Outputs an unsigned hexadecimal integer (uppercase). |
| `%`       | Outputs a literal `%` character. |

---

## Supported Flags

The following flags are supported:

| Flag       | Description |
|------------|-------------|
| `-`        | Left-aligns the output within the given width. |
| `0`        | Pads the output with leading zeros (ignored when `-` is present). |
| `.`        | Specifies precision for numbers and strings. |
| `*`        | Uses the next argument as the width or precision value. |
| `[width]`  | Specifies a minimum field width. |

### Examples of Supported Flags:
1. `%10d` — Prints a decimal integer with a minimum width of 10.
2. `%05d` — Prints a decimal integer padded with leading zeros up to a width of 5.
3. `%-10s` — Left-aligns a string within a field of width 10.
4. `%.3s` — Prints only the first 3 characters of a string.
5. `%*.*d` — Dynamically sets width and precision using arguments from the parameter list.

---

## Usage

### Function Prototype
```c
int ft_printf(const char *format, ...);
