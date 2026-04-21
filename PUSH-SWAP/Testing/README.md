# TESTING



This project includes TWO TESTERS:



- PYTHON TESTER → for PERFORMANCE

- BASH TESTER → for ERROR HANDLING & VALIDATION



## TESTER 1: PYTHON TESTER



This tester evaluates how efficient your algorithm is.



It generates RANDOM INPUTS, runs `push_swap`, and counts how many MOVES are used.



### REQUIREMENTS



- Python 3

- `tqdm` package



Install dependency:



```bash

pip install tqdm

```



Compile your program:



```bash

make

```



### IMPORTANT NOTE



The `push_swap` EXECUTABLE must be in the SAME DIRECTORY as the tester.



Example:



```bash

push_swap/

├── push_swap

├── tester.py

├── Makefile

```



### HOW TO USE



Run:



```bash

python3 tester.py

```



### OPTIONS



```bash

python3 tester.py --tests 100 --numbers 500 --max-moves 5500

```



- `-tests` → number of tests (default: 500)

- `-numbers` → numbers per test (default: 500)

- `-max-moves` → move limit (default: 5500)



### OUTPUT



- Average moves - Maximum moves - Execution time - Number of failing cases

- Failing inputs are saved in:



```bash

failing_cases/

```



## TESTER 2: BASH TESTER (VALIDATION)



This tester checks ERROR HANDLING and SORTING CORRECTNESS.



### REQUIREMENTS



- `push_swap` executable

- `pro_checker` executable



Both must be in the SAME DIRECTORY.



Example:



```bash

push_swap/

├── push_swap

├── pro_checker

├── tester.sh

```



Give permissions if needed:



```bash

chmod +x push_swap pro_checker tester.sh

```



### HOW TO USE



#### 1. ERROR TESTS



```bash

./tester.sh

```



Checks invalid inputs (letters, wrong format, etc.)



Expected: `Error`



#### 2. RANDOM VALIDATION



```bash

./tester.sh -v

```



- Generates RANDOM NUMBERS

- Runs `push_swap`

- Validates using `pro_checker`



#### 3. CUSTOM INPUT TEST



```bash

./tester.sh -v2 "3 2 1 4 5"

```



Runs your program with your own input.



### OUTPUT



- `[OK]` → correct behavior

- `[KO]` → incorrect behavior

- Colored output for readability



### FINAL NOTE



Use BOTH testers together:



- PYTHON TESTER → optimize PERFORMANCE

- BASH TESTER → validate CORRECTNESS



This combination ensures your `push_swap` is BOTH FAST and CORRECT.
