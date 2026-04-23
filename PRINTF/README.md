## **DESCRIPTION**

FT_PRINTF is a C library that reimplements the standard `printf` function from LIBC.

The objective of this project is to understand and use VARIADIC FUNCTIONS in C, while reproducing the behavior of PRINTF with a limited set of conversions. The function FT_PRINTF parses a FORMAT STRING and prints FORMATTED OUTPUT accordingly.

The implementation handles multiple DATA TYPES and ensures behavior close to the original PRINTF, without implementing its internal BUFFER MANAGEMENT.

## REFERENCES

The project follows the official SUBJECT and respects THE NORM coding standard.

SUBJECT: [subject.pdf](./subject.pdf)

## **SUPPORTED CONVERSIONS**

The mandatory part supports:

* `%c` → CHARACTER
* `%s` → STRING
* `%p` → POINTER (HEXADECIMAL)
* `%d` → DECIMAL
* `%i` → INTEGER
* `%u` → UNSIGNED INTEGER
* `%x` → HEXADECIMAL (LOWERCASE)
* `%X` → HEXADECIMAL (UPPERCASE)
* `%%` → PERCENT

FT_PRINTF by supporting additional FORMAT FLAGS and OUTPUT CONTROL.

* → LEFT ALIGNMENT
* `0` → ZERO PADDING
* `.` → PRECISION
* FIELD WIDTH → MINIMUM WIDTH
* `#` → ALTERNATIVE FORM
* `+` → FORCE SIGN
* SPACE → LEADING SPACE FOR POSITIVE NUMBERS

### **WIDTH AND PRECISION**

WIDTH and PRECISION provide fine control over FORMATTED OUTPUT:

* WIDTH defines the MINIMUM number of characters printed
* PRECISION defines:
  * MAXIMUM length for STRINGS
  * MINIMUM number of digits for INTEGERS
  * SPECIAL handling of ZERO values

```c
ft_printf("%10d", 42);
ft_printf("%.5d", 42);
ft_printf("%10.5d", 42);
```

## **INSTRUCTIONS**

### **COMPILATION**

Clone the repository and compile the project:

```bash
git clone <your-repo-link>
cd ft_printf
make
```

This will generate:

```
libftprintf.a
```

### **USAGE**

Include the HEADER in your source file:

```c
#include "ft_printf.h"
```

Compile your program with the STATIC LIBRARY:

```bash
gcc main.c -L. -lftprintf -I. -o program
```

Run:

```bash
./program
```

### **EXAMPLE**

```c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int n = 42;

    printf("Original: %d\\\\n", n);
    ft_printf("Custom: %d\\\\n", n);
    return (0);
}
```

## **RESOURCES**

* `man printf`
* `man stdarg`
* [https://en.cppreference.com/w/c/variadic](https://en.cppreference.com/w/c/variadic)
* ft_printf SUBJECT
