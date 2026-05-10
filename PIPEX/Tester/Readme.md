# ABOUT

42 PIPEX TESTER is a validation tool written in Bash for the `pipex` project as part of the 42 curriculum. The goal of this tester is to verify program correctness against standard shell behavior, check PROCESS SYNCHRONIZATION, and ensure robust MEMORY MANAGEMENT.

This tester compares your custom implementation directly with original UNIX shell piping, facilitating automated checks and making it simple to add your own CUSTOM TEST CASES.

> **IMPORTANT**: This tester is optimized **for LINUX**. You may encounter unexpected behavior or path issues if running on macOS or another OS ❗

# SETUP & USAGE

### 1. Setup

Clone the repository and **move the tester directory into your existing pipex project directory**:

```bash
# Move it into your pipex project folder (replace <path_to_your_pipex> accordingly)
mv Tester <path_to_your_pipex>/

# Navigate into the tester directory
cd <path_to_your_pipex>/Tester

```

*Note: If you prefer to keep the tester folder elsewhere, you must manually adjust the relative path inside `run.sh`.*

Before running the tester, ensure your `Makefile` is fully functional and successfully compiles the executable named `pipex` (including your bonus rules, if applicable) in the parent directory.

### 2. Run

Run the automated test suite using:

```bash
bash run.sh

```

### Execution Flags

You can modify the testing behavior by appending **ONE** of the following flags to the command:

| Flag | Description |
| | |
| `--help` | Displays all available flags and detailed usage instructions. |
| `--hide-err-log` | Suppresses the detailed error log output for a cleaner terminal overview. |
| `--show-valgrind` | Displays full Valgrind output exclusively for test cases where memory errors or leaks were detected. |

### Example:

```bash
bash run.sh --show-valgrind

```


# TESTER LAYOUT & VALIDATION

The script rigorously evaluates your binary against native shell piping across four critical vectors:

* **OUTPUT**: Validates that the exact bytes written to the destination file match the shell's output.
* **EXIT STATUS**: Confirms your program returns the correct standard UNIX exit codes on success and failure.
* **TIME**: Tracks execution duration. Significant discrepancies here usually indicate a synchronization issue where the parent process fails to properly `wait` for all child processes to terminate.
* **LEAKS**: Runs your parent process through Valgrind to ensure all heap-allocated memory is properly freed and no file descriptors are left hanging.


# ADAPT & CUSTOMIZE

Extending the test suite is straightforward. You can append new test cases directly inside `run.sh` by following the established array structure.

Two primary environment variables are exposed for granular test customization:

* `LEAKS_ONLY`
* **`1`**: Subsequent test cases bypass standard bash output comparison and are evaluated **strictly** for memory leaks and fatal runtime crashes. This is highly useful for testing edge cases that lack a direct equivalent syntax in standard Bash.
* **`0`**: Resets validation back to standard full comparison mode.


* `HERE_DOC`
* Accepts a custom string to act as the standard input payload for `here_doc` bonus testing. Always ensure your payload string explicitly terminates with a newline character (`\n`).



### Argument Handling Note

If a test case is configured with fewer than 4 arguments while `LEAKS_ONLY` is set to `0`, the tester will trigger an explicit error message. Because the official subject does not strictly define behavior for invalid argument counts, output parity cannot be reliably measured against Bash—however, your binary must handle the error gracefully without crashing.