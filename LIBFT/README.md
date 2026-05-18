## DESCRIPTION

LIBFT is a custom C library that reimplements a subset of the standard C library functions and extends them with additional utility functions.

The objective of this project is to build a **personal standard library** that will be reused in future C projects. It helps strengthen understanding of **memory management, strings, and linked lists in C**, while enforcing strict coding standards.

The library follows the official subject requirements and must respect THE NORM coding standard.

The final output is a static library (`libft.a`) created using the `ar` command.

## REFERENCES

The project is based on the official subject requirements and standard C library behavior as defined in system man pages.

SUBJECT: [subject.pdf](./subject.pdf)
MAN PAGES: libc functions documentation

## PROJECT STRUCTURE

LIBRARY NAME: libft.a

FILES TO SUBMIT:

* Makefile
* libft.h
* ft_*.c

MAKEFILE RULES:

* NAME
* all
* clean
* fclean
* re

## COMPILATION RULES

* All `.c` files must compile with:

```bash
-Wall -Wextra -Werror
```

* The library must be created using:

```bash
ar rc libft.a
ranlib libft.a
```

* No global variables are allowed.
* Helper functions must be declared as `static` when possible.
* No unused files should be submitted.

## PART 1 LIBC FUNCTIONS

This part reimplements standard C library functions with the prefix `ft_`.
These functions must strictly follow the behavior of their original libc counterparts.

### CHARACTER CHECKING

* ft_isalpha
* ft_isdigit
* ft_isalnum
* ft_isascii
* ft_isprint

### STRING FUNCTIONS

* ft_strlen
* ft_strlcpy
* ft_strlcat
* ft_strchr
* ft_strrchr
* ft_strncmp
* ft_strnstr
* ft_strdup

### MEMORY FUNCTIONS

* ft_memset
* ft_bzero
* ft_memcpy
* ft_memmove
* ft_memchr
* ft_memcmp
* ft_calloc

### CASE CONVERSION

* ft_toupper
* ft_tolower

### STRING TO INT

* ft_atoi

## PART 2 ADDITIONAL FUNCTIONS

These functions extend libc functionality and provide higher-level utilities.

### STRING MANIPULATION

* ft_substr → extract substring
* ft_strjoin → concatenate strings
* ft_strtrim → trim characters from ends
* ft_split → split string into array
* ft_strmapi → map function over string
* ft_striteri → apply function to string in-place

### INTEGER CONVERSION

* ft_itoa → convert int to string

### FILE DESCRIPTORS OUTPUT

* ft_putchar_fd → print char
* ft_putstr_fd → print string
* ft_putendl_fd → print string + newline
* ft_putnbr_fd → print number

## PART 3 LINKED LISTS

This part introduces a generic singly linked list structure:

```c id="lst0"
typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;
```

### LIST FUNCTIONS

* ft_lstnew → create new node
* ft_lstadd_front → add node at beginning
* ft_lstsize → count nodes
* ft_lstlast → get last node
* ft_lstadd_back → add node at end
* ft_lstdelone → delete single node
* ft_lstclear → delete entire list
* ft_lstiter → apply function to each node
* ft_lstmap → create new mapped list

## TECHNICAL CONSTRAINTS

* No global variables allowed
* Static helper functions required when needed
* Only required files must be submitted
* Must comply with strict compilation flags
* Must use `ar` (libtool is forbidden)
* Library must be created at repository root

## USAGE

### BUILD

```bash
make
```

This generates:

```txt id="lib0"
libft.a
```

### INCLUDE IN PROJECT

```c id="inc0"
#include "libft.h"
```

### COMPILE WITH LIBRARY

```bash id="cmp0"
gcc main.c -L. -lft -I. -o program
```

### RUN

```bash id="run0"
./program
```

## EXAMPLE

```c id="ex0"
#include <stdio.h>
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello Libft");

    printf("%s\n", str);
    return 0;
}
```

## LEARNING GOALS

This project teaches:

Memory allocation (malloc/free)
Pointer manipulation
String and memory handling
Building reusable libraries
Linked list data structures
Code organization in C
Writing clean modular functions

