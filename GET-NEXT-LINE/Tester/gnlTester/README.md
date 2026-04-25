# **GNLTESTER**

GNLTESTER is a TESTER for the GET_NEXT_LINE project from the 42 curriculum.

It checks your GET_NEXT_LINE implementation by running multiple TEST CASES with different BUFFER_SIZE values. It also detects SEGMENTATION FAULTS, TIMEOUTS, and MEMORY LEAKS.

Clone this tester inside your GET_NEXT_LINE repository.

## **REQUIREMENTS**

Before using the tester, make sure the required PACKAGES are installed.

### **LINUX PACKAGES**

```bash

sudo apt update
sudo apt install build-essential gcc g++ clang valgrind make

```

### **OPTIONAL DOCKER PACKAGE**

```bash

sudo apt install docker.io

```

## **INSTALLATION**

Clone the tester inside your GET_NEXT_LINE repository:

```bash

git clone <tester-repo-link> gnlTester
cd gnlTester

```

Your repository should look like this:

```

get_next_line/

├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── get_next_line_bonus.c
├── get_next_line_utils_bonus.c
├── get_next_line_bonus.h
└── gnlTester/

```

## **COMMANDS**

```bash

make m          # LAUNCH MANDATORY TESTS
make b          # LAUNCH BONUS TESTS
make a          # LAUNCH MANDATORY + BONUS TESTS

make dockerm    # LAUNCH MANDATORY TESTS IN LINUX DOCKER CONTAINER
make dockerb    # LAUNCH BONUS TESTS IN LINUX DOCKER CONTAINER
make dockera    # LAUNCH MANDATORY + BONUS TESTS IN LINUX DOCKER CONTAINER

```

For RIGOROUS TESTING, run the tests with VALGRIND using a LINUX environment:

```bash

make dockerm
make dockerb
make dockera

```

## **BUFFER SIZE TESTS**

The tester runs GET_NEXT_LINE with different BUFFER_SIZE values, usually including:

- BUFFER_SIZE=1
- BUFFER_SIZE=42
- BUFFER_SIZE=10000000

This helps verify that your implementation works with SMALL BUFFERS, NORMAL BUFFERS, and VERY LARGE BUFFERS.

## **TIMEOUT CONFIGURATION**

You can change the TIMEOUT value in the MAKEFILE:

```

TIMEOUT_US = 1000000

```

- Increase TIMEOUT_US if your program times out too quickly
- Decrease TIMEOUT_US for faster tests

A TIMEOUT usually means your function may have an INFINITE LOOP or is too slow for a specific case.

## **DOCKER SETUP FOR 42 MAC**

To setup DOCKER in GOINFRE on a 42 MAC:

```bash

rm -rf ~/Library/Containers/com.docker.docker
rm -rf ~/.docker
rm -rf /goinfre/${USER}/docker /goinfre/${USER}/agent
mkdir -p /goinfre/${USER}/docker /goinfre/${USER}/agent
ln -s /goinfre/${USER}/agent ~/Library/Containers/com.docker.docker
ln -s /goinfre/${USER}/docker ~/.docker

```

This moves DOCKER data to GOINFRE and avoids filling your HOME directory.

## **MOK / MKO**

MOK and MKO are tests related to MALLOC SIZE.

These tests check how much MEMORY is allocated by your implementation.

They are useful for debugging, but they should not normally be tested by the MOULINETTE.
