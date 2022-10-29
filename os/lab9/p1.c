
/* CS20B1085 gugulothu ravindar
Given 2 threads, schedule the order of execution in such a way that Thread A has to wait for Thread B and vice versa. 
In other words, given the code below you must guarantee that Statement A1 happens before Statement B2 and Statement B1 happens before Statement A2.

Thread A
//Statement A1
//Statement A2

Thread B
//Statement B1
//Statement B2

Note: Your solution should not enforce too many constraints. 
For ex: there is no mention about the order of execution of A1 and B1. Therefore, either order should be possible. */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>
#include <sys/wait.h>

sem_t semaphore1, semaphore2;

void *thread_fn1(void* num)

{
    if(num == (void*)0)
    {
        sem_init(&semaphore1,0,1);
        sem_wait(&semaphore1) ;
        printf("statement A1\n") ;
        sem_post(&semaphore2) ;
        sem_wait(&semaphore1) ;
        printf("statement A2\n") ;
        sem_post(&semaphore2) ;
    }
    if(num == (void*)1)
    {
        sem_init(&semaphore2,0,1);
        sem_wait(&semaphore2) ;
        printf("statement B1\n") ;
        sem_post(&semaphore1) ;
        sem_wait(&semaphore2) ;
        printf("statement B2\n") ;
        sem_post(&semaphore1) ;
    }
}


int main()
{
    pthread_t t1,t2;
    sem_init(&semaphore1, 0, 1);
    sem_init(&semaphore2, 0, 1);
    
    wait(NULL);
    pthread_create(&t1, NULL, &thread_fn1, (void*)0);//thread creation
    pthread_create(&t2, NULL, &thread_fn1, (void*)1);//thread creation
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&semaphore1) ;
    sem_destroy(&semaphore2) ;

    return 0;
}






