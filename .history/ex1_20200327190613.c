/*************************************
 * Lab 4 Exercise 1
 * Name: 
 * Student No:
 * Lab Group:
 **************************************/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include "my_semaphore.h"

//intialise everything in lock here 
void initialise(custom_lock* lock) {

    //modify here

    sem_init(&lock->mutex, 0, 0);
    sem_init(&lock->write_lock, 0, 0);
    int i;
    for(i=0;i<lock->max_threads;i++){
        sem_init(&lock->array[0],0,0);
    }
}

//wait takes in a custom struct
//we want the thread to be added to our semaphore here
void wait(custom_lock* lock) {

    //modify here

    sem_wait(&lock->mutex); 
}

//notify_all takes in a custom struct
//we want to wake all the sleeping threads here!
void notify_all(custom_lock* lock) {
    
    //modify here

    int i;
    for (i = 0; i < lock->max_threads; i++) {
        //sem_post(&lock->mutex);
        sem_wait(&lock->array[0])
        //wait for this value to be written before moving on
        sem_wait(&lock->write_lock);
    }
}

//free anything allocated here
void cleanup(custom_lock* lock) {

    //modify here

    sem_destroy(&lock->mutex);
    sem_destroy(&lock->write_lock);
}

