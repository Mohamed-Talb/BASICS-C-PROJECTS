# ABOUT

PHILOSOPHERS is a system programming project written in C as part of the 42 curriculum. The goal of this project is to learn the basics of threading a process, creating threads, and exploring the proper use of mutexes.

This project implements the classic "Dining Philosophers" synchronization problem. Philosophers sit at a round table alternating between eating, thinking, and sleeping. To eat spaghetti, a philosopher requires two forks (left and right). The challenge lies in designing a highly optimized, race-free simulation where resources are shared concurrently without causing deadlocks or allowing any philosopher to starve.

# REFERENCES

The project follows the official SUBJECT and respects THE NORM coding standard.

* **SUBJECT**:  [subject.pdf](./Philosophers.en.pdf)

# INSTALLATION & USAGE

Clone the repository and build the project using MAKE.

```bash
git clone <your-repo-link>
cd philo
make

```

Run the program using the required arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

```

### Arguments Overview:

* `number_of_philosophers`: The number of philosophers sitting at the table (also equals the total number of forks).
* `time_to_die` (in ms): If a philosopher does not start eating within this timeframe since the start of their last meal or the simulation start, they die.
* `time_to_eat` (in ms): The time it takes for a philosopher to eat while holding two forks.
* `time_to_sleep` (in ms): The time a philosopher spends sleeping.
* `number_of_times_each_philosopher_must_eat` *(optional)*: The simulation stops successfully if all philosophers eat at least this many times. If omitted, the simulation runs until a philosopher dies.

### Example:

```bash
# 5 philosophers, die after 800ms, eat for 200ms, sleep for 200ms
./philo 5 800 200 200

```

# PROJECT REQUIREMENTS

The implementation must adhere to strict global and mandatory constraints:

* **NO GLOBAL VARIABLES**: The use of global variables is strictly forbidden.
* **NO DATA RACES**: The program must be entirely free of data races.
* **NO LIBFT**: Custom `libft` libraries are **NOT** authorized for this project.

### Core Architecture (`philo/`)

* **Threading**: Each philosopher must be represented as a separate thread.
* **Mutexes**: There is one fork between each pair of philosophers. Each fork's state must be strictly protected with a mutex to prevent fork duplication.
* **Authorized Functions**: `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`.

# LOGS & ERROR HANDLING

Any state change of a philosopher must be formatted exactly as follows to the standard output:

* `timestamp_in_ms X has taken a fork`
* `timestamp_in_ms X is eating`
* `timestamp_in_ms X is sleeping`
* `timestamp_in_ms X is thinking`
* `timestamp_in_ms X died`

*(Where `timestamp_in_ms` is the current timestamp in milliseconds and `X` is the philosopher's index number ranging from 1 to N)*.

### Log Constraints:

* Displayed state messages must never overlap or interleave with another message.
* A message announcing a philosopher's death must be displayed within **10 ms** of their actual time of death.
* All heap-allocated memory must be properly freed; memory leaks will not be tolerated. Functions must never quit unexpectedly (e.g., segmentation faults).