/*************************************
 * Lab 4 Exercise 1
 * Name: 
 * Student No:
 * Lab Group:
 **************************************/

#include <semaphore.h>

typedef struct {

    //global lock
    sem_t mutex;
    int current;
    sem_t second;
    //lock for sort_value function
    sem_t write_lock;
    sem_t* array;
    //max threads that can be waiting on this lock
    int max_threads;

} custom_lock;

