# printfTester

## **DESCRIPTION**

PRINTFTESTER is a TESTING TOOL for the FT_PRINTF project from the 42 curriculum.

It compares the OUTPUT of your FT_PRINTF with the original PRINTF and detects:

* WRONG OUTPUT
* RETURN VALUE ERRORS
* SEGMENTATION FAULTS
* MEMORY LEAKS (using VALGRIND on LINUX)

This tester works on both LINUX and MACOS environments. It includes TIMEOUT handling and SIGNAL DETECTION (SIGSEGV).

## **REQUIREMENTS**

Before using the tester, make sure the following PACKAGES are installed:

```bash
sudo apt update
sudo apt install build-essential g++ clang libc++-dev libc++abi-dev libstdc++-12-dev valgrind
```

These packages provide:

* C COMPILER (GCC / CLANG)
* C++ COMPILER (G++)
* C++ STANDARD LIBRARY (IOSTREAM, VECTOR, etc.)
* MEMORY CHECKING TOOL (VALGRIND)

## **INSTALLATION**

move the tester to  your FT_PRINTF project directory:

```bash
cd printfTester
```

Make sure your `libftprintf.a` is located in the ROOT of your FT_PRINTF project.

## **COMMANDS**

### **STANDARD TESTS**

```bash
make m                  # LAUNCH MANDATORY TESTS
make b                  # LAUNCH BONUS TESTS
make a                  # LAUNCH ALL TESTS (MANDATORY + BONUS)

make [CATEGORY]         # LAUNCH CATEGORY TEST (EX: make s)
make [CATEGORY] [N]     # LAUNCH SPECIFIC TEST (EX: make s 42)
```

### **DOCKER TESTS**

```bash
make dockerm            # MANDATORY TESTS IN DOCKER
make dockerb            # BONUS TESTS IN DOCKER
make dockera            # ALL TESTS IN DOCKER

make docker[CATEGORY]         # CATEGORY TEST IN DOCKER (EX: make dockers)
make docker[CATEGORY] [N]     # SPECIFIC TEST IN DOCKER (EX: make dockers 42)
```

### **SPECIFIER MAPPING**

```
X = UPPERX
% = PERCENT
```

### **CONFIGURATION**

You can adjust the TIMEOUT in the MAKEFILE:

```
TIMEOUT_US = 400000
```

* DECREASE → FASTER TESTS
* INCREASE → AVOID TIMEOUT ERRORS
