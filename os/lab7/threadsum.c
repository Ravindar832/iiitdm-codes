#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int sum[2];

void *thread_fn(void *arg)//work done by thread is defined by this function
{
    int id = (int) arg;
    int start = id*5;
    int i = 0;
    
    for(i = 0; i < 5; i++)
    {
        sum[id] += i + start;
    }
    
    return NULL;
    
}

int main()
{
    pthread_t t1;
    pthread_t t2;
    
    
    pthread_create(&t1,NULL,&thread_fn,(void *)0);//create thread 1
    pthread_create(&t2,NULL,&thread_fn,(void *)1);//create thread 2
    
    pthread_join(t1,NULL);//return value of thread 1
    pthread_join(t2,NULL);//return value of thread 1

    int total_sum = sum[0]+sum[1];
    
    printf("Sum of all integers in array1 amd array 2:%d",total_sum);
}