# ABOUT

PIPEX is a system programming project written in C as part of the 42 curriculum. The goal of this project is to explore and understand standard UNIX MECHANISMS in detail, specifically focusing on REDIRECTION, PROCESS CREATION, and handling PIPES.

This project consists of mimicking the exact behavior of standard shell piping and file redirection by utilizing fundamental UNIX I/O system calls, managing file descriptors, and routing data between child processes. The implementation follows the official SUBJECT and respects THE NORM coding standard.


# REFERENCES

The project follows the official SUBJECT and respects THE NORM coding standard.

* **SUBJECT**:  [subject.pdf](./pipex.en.pdf)


# INSTALLATION & USAGE

Clone the repository and build the project using MAKE.

```bash
git clone <your-repo-link>
cd pipex
make

```

Run the program using:

```bash
./pipex file1 cmd1 cmd2 file2

```

### Example 1:

```bash
./pipex infile "ls -l" "wc -l" outfile

```

Behaves exactly like the following shell command:

```bash
< infile ls -l | wc -l > outfile

```

### Example 2:

```bash
./pipex infile "grep a1" "wc -w" outfile

```

Behaves exactly like the following shell command:

```bash
< infile grep a1 | wc -w > outfile

```


# PROJECT REQUIREMENTS

The external functions authorized for this project are strictly limited to:

* `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`
* `ft_printf` (or any equivalent YOU coded)
* Custom `libft` library is authorized

System requirements during development generally include:

* GNU MAKE
* GCC / CC compiler
* UNIX-BASED SYSTEM (LINUX OR MACOS)


# BONUS FEATURES

The BONUS part extends the program's capabilities to handle advanced shell redirection features. Bonuses must be placed in separate `_bonus` files and are evaluated independently.

Compile the bonus build:

```bash
make bonus

```

### 1. Multiple Pipes

Handle an arbitrary number of commands piped together sequentially:

```bash
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

```

Should behave exactly like:

```bash
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

```

### 2. Here_doc Support

Support `<<` and `>>` redirections when the first parameter is explicitly set to `here_doc`:

```bash
./pipex here_doc LIMITER cmd cmd1 file

```

Should behave exactly like:

```bash
cmd << LIMITER | cmd1 >> file

```

> **IMPORTANT**: The bonus part will ONLY be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been entirely completed and functions without malfunctioning or missing requirements.


# NOTES & ERROR HANDLING

* **Error Handling**: If unsure about specific behaviors, errors must be handled exactly the same way as the standard shell command handles them.
* **Memory Management**: All heap-allocated memory must be properly freed; memory leaks are strictly not tolerated.
* **Stability**: Functions must never quit unexpectedly (e.g., segmentation fault, bus error, double free). If unexpected termination occurs, the project is considered non-functional and receives a 0.
* **Core Mechanisms**: Mastery of `fork`, `pipe`, `dup2`, and `execve` is essential to properly link the standard output of one process to the standard input of the next without leaving hanging file descriptors.