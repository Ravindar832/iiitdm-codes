
//cs20b1085  gugulothu ravindar
/* Write a program where you create 2 processes. In each process,
  create two threads. In each thread, consider one global variable 
  and one local variable. Perform some operation  in local and global variable. 
  Print the process id, and thread id of the respective process and thread, local 
  variable address, global variable address and values of local and global variables in each thread. */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int global_variable = 1;

void *thread_fn(void *arg)
{
    int local_variable = 2;
    printf("\nThread ID:%lu",pthread_self());
    printf("\nGlobal value: %d\t Address of the global variable:%p",global_variable,&global_variable);
    printf("\nLocal value: %d\t Address of the local variable::%p",local_variable,&local_variable);
}

int main()
{
    pid_t pid;
    pthread_t t1,t2;
    pid = fork();
    if(pid != 0)   //parent process
    {
        wait(NULL);
        printf("\n Parent Process, with Process ID: %d\n", getpid());
        pthread_create(&t1,NULL,&thread_fn,NULL);//thread creation
        pthread_join(t1,NULL);
        printf("\n");
        pthread_create(&t2,NULL,&thread_fn,NULL);//thread creation
        pthread_join(t2,NULL);
    }
    else
    {
        printf("\n Child Process, with Process ID: %d\n", getpid());
        pthread_create(&t1,NULL,&thread_fn,NULL);//thread creation
        pthread_join(t1,NULL);
        printf("\n");
        pthread_create(&t2,NULL,&thread_fn,NULL);//thread creation
        pthread_join(t2,NULL);
        printf("\n");
    }
    return 0;
}