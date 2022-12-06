#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

#define N 5
#define Thinking 0
#define Hungary 1
#define eating 2

int State[N];
sem_t mutex;
sem_t S[N];