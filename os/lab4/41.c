#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
// #include <sys/wait.h>
#include <unistd.h>

#define  SIZE 1000 
int a[SIZE];
int main()
{
    
    int n, i;
    printf("enter the count of elements in array  : ");
    scanf("%d",&n);
    printf("enter the elemets  :\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    
    int pid = fork();
    
    if(pid == 0){// For Child Process, pid = 0
    printf("elements of array:");
    for(int i=0;i<n;i++){
       printf("%d  ",a[i]); 
    }
    printf("\n addresses of array elements");
    for(int i=0;i<n;i++){
        printf("%p  ",&a[i]);
    }
    int maxmimum=a[0];
    for(int i=0;i<n;i++)
    {
     if(a[i]>maxmimum)
      maxmimum=a[i];
     }
     printf(" \n Maximum element is %d",maxmimum);
     
     printf(" \nchild id :");
     printf("%d",getpid());
     printf("\n Parent Id:");
     printf("%d",getppid());


    }
    else if (pid > 0){

    printf("\n elements of array");
    for(int i=0;i<n;i++){
       printf("%d  ",a[i]);
    }
    printf(" \n addresses of array elements");
    for(int i=0;i<n;i++){
        printf("%p  ",&a[i]);
    }
    int minimum=a[0];
    for(int i=0;i<n;i++)
    {
    if(a[i]<minimum)
    minimum=a[i];
    }
    printf("Minimum element is %d",minimum);
    
    printf(" \nchild id :");
    printf("%d",getpid());
    printf("\n Parent Id:");
    printf("%d",getppid());

    }
    else{
        printf("Invalid Process\n\n");
        
    }
    
    
    return 0;
}