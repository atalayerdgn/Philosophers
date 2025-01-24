# Dining Philosophers Problem

## Overview
The Dining Philosophers problem is a classic synchronization problem that illustrates the challenges of avoiding deadlock and ensuring proper resource allocation in a multithreaded environment. This implementation follows the rules for the mandatory part:

1. **Philosophers as Threads**: Each philosopher is represented as a separate thread using `pthread_t`.
2. **Forks as Shared Resources**: There is one fork between each pair of philosophers. Each philosopher has access to a fork on their left and right sides. If there is only one philosopher, there is only one fork available.
3. **Fork State Protection**: To prevent race conditions or duplication of forks, each fork's state is protected using a mutex.

## Implementation Details
- **Threads**: Each philosopher's actions (thinking, picking up forks, eating, putting down forks) are executed in a separate thread created with `pthread_create`.
- **Mutexes**: Each fork is associated with a mutex to ensure only one philosopher can access it at a time.

## `pthread_t` Functions Explained

### `pthread_create`
**Declaration**:
```c
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
```
- **Purpose**: Creates a new thread.
- **Parameters**:
  - `pthread_t *thread`: A pointer to the thread identifier.
  - `const pthread_attr_t *attr`: Attributes for the thread (can be `NULL` for default attributes).
  - `void *(*start_routine)(void *)`: The function to execute in the new thread.
  - `void *arg`: Argument passed to the `start_routine` function.
- **Return Value**: Returns `0` on success or an error code on failure.

### `pthread_join`
**Declaration**:
```c
int pthread_join(pthread_t thread, void **retval);
```
- **Purpose**: Waits for a thread to finish execution.
- **Parameters**:
  - `pthread_t thread`: The thread to join.
  - `void **retval`: A pointer to store the return value of the thread (can be `NULL` if not needed).
- **Return Value**: Returns `0` on success or an error code on failure.

### `pthread_mutex_init`
**Declaration**:
```c
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
```
- **Purpose**: Initializes a mutex.
- **Parameters**:
  - `pthread_mutex_t *mutex`: A pointer to the mutex to initialize.
  - `const pthread_mutexattr_t *attr`: Attributes for the mutex (can be `NULL` for default attributes).
- **Return Value**: Returns `0` on success or an error code on failure.

### `pthread_mutex_lock`
**Declaration**:
```c
int pthread_mutex_lock(pthread_mutex_t *mutex);
```
- **Purpose**: Locks a mutex, blocking if the mutex is already locked.
- **Parameters**:
  - `pthread_mutex_t *mutex`: The mutex to lock.
- **Return Value**: Returns `0` on success or an error code on failure.

### `pthread_mutex_unlock`
**Declaration**:
```c
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```
- **Purpose**: Unlocks a mutex.
- **Parameters**:
  - `pthread_mutex_t *mutex`: The mutex to unlock.
- **Return Value**: Returns `0` on success or an error code on failure.

### `pthread_mutex_destroy`
**Declaration**:
```c
int pthread_mutex_destroy(pthread_mutex_t *mutex);
```
- **Purpose**: Destroys a mutex, freeing resources associated with it.
- **Parameters**:
  - `pthread_mutex_t *mutex`: The mutex to destroy.
- **Return Value**: Returns `0` on success or an error code on failure.

## How It Works
1. **Initialization**: Mutexes are created for each fork, and threads are created for each philosopher.
2. **Thread Execution**: Each philosopher alternates between thinking, attempting to pick up forks, eating, and putting down forks.
3. **Synchronization**: Mutexes ensure that no two philosophers can use the same fork simultaneously.
4. **Completion**: The main thread waits for all philosopher threads to complete using `pthread_join`.
5. **Cleanup**: Mutexes are destroyed to release resources.

## Example Workflow
1. Philosopher 1 thinks.
2. Philosopher 1 locks the left fork's mutex and the right fork's mutex.
3. Philosopher 1 eats.
4. Philosopher 1 unlocks both forks' mutexes.
5. Repeat for other philosophers.

## Compilation and Execution
To compile the program:
```bash
make
```
To run the program:
```bash
./philo 5 500 500 800 (5 for optional)
[number_of_philosophers,time_to_die,time_to_eat,time_to_sleep,number_of_times_each_philosopher_must_eat]
```
