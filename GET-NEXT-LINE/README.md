# GET_NEXT_LINE PROJECT

GET_NEXT_LINE is a C FUNCTION that reads and returns a LINE from a FILE DESCRIPTOR.

The goal of this project is to implement a function that allows reading a FILE or STANDARD INPUT line by line, without loading the entire content into memory. This requires efficient BUFFER MANAGEMENT and careful MEMORY HANDLING.

The function prototype is:

```c

char *get_next_line(int fd);

```

## **PROJECT STRUCTURE**

- `get_next_line.c` → MAIN IMPLEMENTATION
- `get_next_line_utils.c` → HELPER FUNCTIONS
- `get_next_line.h` → HEADER FILE
- `BONUS` → MULTIPLE FILE DESCRIPTORS SUPPORT

## **INSTRUCTIONS**

### **COMPILATION**

Compile with a chosen BUFFER_SIZE:

```bash

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

```

### **USAGE**

```c

char *line = get_next_line(fd);

```

### **RETURN VALUES**

- LINE READ → RETURNED STRING
- END OF FILE → NULL
- ERROR → NULL

## **FILE DESCRIPTOR BASICS**

In C, FILE DESCRIPTORS represent INPUT/OUTPUT STREAMS:

- `0` → STDIN
- `1` → STDOUT
- `2` → STDERR

Common FUNCTIONS:

- `open()` → OPEN FILE
- `read()` → READ DATA
- `write()` → WRITE DATA
- `close()` → CLOSE FILE
