This project has been created as part of the 42 curriculum by bfernan2.

Description

Philosophers is a project from the 42 School curriculum based on the classic Dining Philosophers Problem, originally formulated by Edsger Dijkstra in 1965. It serves as an introduction to concurrent programming, focusing on the challenges of thread synchronization and shared resource management.

The simulation places a given number of philosophers around a round table. Each philosopher alternates between three states: thinking, eating, and sleeping. To eat, a philosopher must pick up both forks adjacent to them — one on the left and one on the right. Since forks are shared between neighbors, the program must carefully manage access to avoid deadlocks, data races, and starvation.

The simulation ends when a philosopher dies of starvation, or when all philosophers have eaten a specified number of times.

This project is implemented in C using POSIX threads (pthreads) and mutexes for synchronization.


Instructions

Compilation

bashmake        # Build the executable
make re     # Clean and rebuild from scratch
make clean  # Remove object files
make fclean # Remove object files and executable

Execution

bash./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]

ArgumentTypeDescriptionnumber_of_philosophersRequiredNumber of philosophers and forks at the tabletime_to_dieRequiredTime in milliseconds before a philosopher dies without eatingtime_to_eatRequiredTime in milliseconds a philosopher takes to eattime_to_sleepRequiredTime in milliseconds a philosopher takes to sleepnumber_of_times_each_philosopher_must_eatOptionalIf set, the simulation stops once all philosophers have eaten this many times

Examples

bash# No philosopher should die
./philo 5 800 200 200

# One philosopher — will die (cannot grab two forks alone)
./philo 1 800 200 200

# Stops after each philosopher has eaten 7 times
./philo 5 800 200 200 7

# A philosopher should die
./philo 4 310 200 100


Resources

Documentation & References


Dining Philosophers Problem — Wikipedia
POSIX Threads Programming — Lawrence Livermore National Laboratory
pthread_mutex_lock — Linux man page
pthread_create — Linux man page
Race Conditions and Mutexes — GeeksforGeeks