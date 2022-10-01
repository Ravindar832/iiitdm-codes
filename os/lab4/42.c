#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
// #include <sys/wait.h>
#include <unistd.h>
int n = 100;

int main(){
    int n,i,j,a;
    // int *array = malloc(n * sizeof * array);
    // printf("enter the count of elements in array  : ");
    // scanf("%d",&n);
    // printf("enter the elemets  :\n");
    // for(i=0;i<n;i++){
    //     scanf("%d",&array[i]);
    // }
    
    
    int pid = fork();
    
    if(pid == 0){// For Child Process, pid = 0
    int *array = malloc(n * sizeof * array);
    printf("enter the count of elements in array  : ");
    scanf("%d",&n);
    printf("enter the elemets  :\n");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    printf("elements of array:");
    for(int i=0;i<n;i++){
       printf("%d  ",array[i]); 
    }
    printf("\n addresses of array elements");
    for(int i=0;i<n;i++){
        printf("%p  ",&array[i]);
    }
    for (i = 0; i < n; ++i) 
        {
 
            for (j = i + 1; j < n; ++j)
            {
 
                if (array[i] > array[j]) 
                {
                    
                    a =  array[i];
                    array[i] = array[j];
                    array[j] = a;
 
                }
 
            }
 
        }
 
        printf("The arrays arranged in ascending order are given below \n");
        for (i = 0; i < n; ++i)
            printf("%d\n", array[i]);
    
     
     printf(" \nchild id :");
     printf("%d",getpid());
     printf("\n Parent Id:");
     printf("%d",getppid());


    }
    else if (pid > 0){
    wait(0);
    int *array = malloc(n * sizeof * array);
    printf("enter the count of elements in array  : ");
    scanf("%d",&n);
    printf("enter the elemets  :\n");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    printf("\n elements of array");
    for(int i=0;i<n;i++){
       printf("%d  ",array[i]);
    }
    printf(" \n addresses of array elements");
    for(int i=0;i<n;i++){
        printf("%p  ",&array[i]);
    }
    for(int i = 0; i<n/2; i++){
        a = array[i];
        array[i] = array[n-i-1];
        array[n-i-1] = a;
    }
 
    printf("The arrays arranged in reverse order are given below \n");
    for (i = 0; i < n; ++i)
        printf("%d\n", array[i]);
    
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