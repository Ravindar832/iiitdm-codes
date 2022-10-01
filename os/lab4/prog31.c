#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
// #include <sys/wait.h>
#include <unistd.h>

int main()
{
    
    int pid = fork();
    
    if(pid == 0){// For Child Process, pid = 0
   
     system("./prog32");
     printf(" \n process id :");
     printf("%d",getpid());
     printf("\n Parent Id:");
     printf("%d",getppid());


    }
    else if (pid > 0){

    printf("IIITDM KANCHEEPURAM");
    
    printf(" \n process id :");
    printf("%d",getpid());
    printf("\n Parent Id:");
    printf("%d",getppid());

    }
    else{
        printf("Invalid Process\n\n");
        
    }
    
    
    return 0;
}