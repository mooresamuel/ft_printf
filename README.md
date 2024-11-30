A custom implementation of the printf function for 42 London projects, written in C. This implementation supports various format specifiers and flags, enabling formatted output for strings, characters, integers, unsigned integers, pointers, and hexadecimal values.

Table of Contents
Introduction
Supported Format Specifiers
Supported Flags
Usage
Function Overview
Compilation and Testing
License
Introduction
The ft_printf function replicates the behavior of the standard printf function, providing formatted output capabilities. This project was created as part of the curriculum at 42 London and demonstrates proficiency in handling variable argument lists, parsing format strings, and applying formatting rules.

Supported Format Specifiers
The ft_printf function supports the following format specifiers:

Specifier	Description
c	Outputs a single character.
s	Outputs a string.
p	Outputs a pointer address in hexadecimal format.
d or i	Outputs a signed decimal integer.
u	Outputs an unsigned decimal integer.
x	Outputs an unsigned hexadecimal integer (lowercase).
X	Outputs an unsigned hexadecimal integer (uppercase).
%	Outputs a literal % character.
Supported Flags
The following flags are supported:

Flag	Description
-	Left-aligns the output within the given width.
0	Pads the output with leading zeros (ignored when - is present).
.	Specifies precision for numbers and strings.
*	Uses the next argument as the width or precision value.
[width]	Specifies a minimum field width.
Examples of Supported Flags:
%10d — Prints a decimal integer with a minimum width of 10.
%05d — Prints a decimal integer padded with leading zeros up to a width of 5.
%-10s — Left-aligns a string within a field of width 10.
%.3s — Prints only the first 3 characters of a string.
%*.*d — Dynamically sets width and precision using arguments from the parameter list.
Usage
Function Prototype
c
Copy code
int ft_printf(const char *format, ...);
Example Code
c
Copy code
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "World"); // Outputs: Hello, World!
    ft_printf("Hex: %#x\n", 255);       // Outputs: Hex: 0xff
    ft_printf("Int: %10d\n", 42);       // Outputs: Int:         42
    return 0;
}
Function Overview
Key Components:
format_print:

Handles different format specifiers (c, s, p, x, etc.).
Calls helper functions like ft_string, ft_char, ft_integer, etc., to process specific data types.
process_flags:

Parses the format string for flags (-, 0, ., *) and handles width and precision.
Updates the t_box structure to track formatting details for the current conversion.
Helper Functions:

ft_char: Handles character output.
ft_string: Handles string output with precision and width adjustments.
ft_integer: Processes signed integers.
ft_unsigned: Processes unsigned integers.
ft_hex: Handles hexadecimal formatting.
ft_pointer: Handles pointer address formatting.
Compilation and Testing
Compilation
To compile the ft_printf library:

bash
Copy code
gcc -Wall -Wextra -Werror ft_printf.c -o ft_printf
Testing
You can create a test program or use a unit-testing framework like Criterion or Libftest to validate the behavior of your ft_printf implementation.

Example Test:
c
Copy code
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    ft_printf("Custom printf: %d\n", 42);
    printf("Original printf: %d\n", 42);
    return 0;
}
License
This project is available under the MIT License. Feel free to use, modify, and distribute the code as per the license terms.

Happy coding! 🚀
