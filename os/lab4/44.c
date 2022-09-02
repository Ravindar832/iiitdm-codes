#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
// #include <sys/wait.h>

int main()
{
    
    int pid = fork();
    if (pid != 0)//parent
    {
        wait(NULL);
        pid = fork();
        if (pid != 0)//parent
        {
            wait(NULL);
            printf("Parent Process: My ID is: %d and Parent ID is: %d\n", getpid(), getppid());
        }
        else//child 1
        {
            printf("Child Level 1: My ID is: %d and Parent ID is: %d\n", getpid(), getppid());
            epidit(1);
        }
    }
    else//child 2
    {
        pid = fork() && fork();
        if (pid != 0)//child 1
        {
            wait(NULL);
            printf("Child Level 1: My ID is: %d and Parent ID is: %d\n", getpid(), getppid());
        }
        else//child 2
        {
            printf("Child Level 2: My ID is: %d and Parent ID is: %d\n", getpid(), getppid());
            epidit(1);
        }
    }
    return 0;
}