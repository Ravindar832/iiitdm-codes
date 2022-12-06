// cs20b1085 gugulothu ravindar


#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define MaxItems 5 // Maximum items a producer can produce or a consumer can consume
#define BufferSize 5 // Size of the buffer

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;

void *produce_item() // Producer Function
{
  int item;
  int flag = 10;
  while (flag--)
  {
    item = rand() % 100; // Produce an random item
    sem_wait(&empty); //decrement empty
    pthread_mutex_lock(&mutex);
    buffer[in] = item; //store item in the buffer
    printf("Producer: Produced Item %d in Buffer\n", buffer[in]);
    in = (in + 1) % BufferSize; //increment in by 1
    pthread_mutex_unlock(&mutex);
    sem_post(&full); //increment full
  }
}

void *consume_item() // Consumer Funtion
{
  int flag = 10;
  while (flag--)
  {
    sem_wait(&full); //decrement full
    pthread_mutex_lock(&mutex);
    int item = buffer[out]; //pop item
    printf("Consumer: Removed Item %d from Buffer\n", buffer[out]);
    out = (out + 1) % BufferSize;
    pthread_mutex_unlock(&mutex);
    sem_post(&empty); //increment empty
  }
}

int main()
{

  pthread_t P1, C1;
  pthread_mutex_init(&mutex, NULL);
  sem_init(&empty, 0, BufferSize);
  sem_init(&full, 0, 0);

  pthread_create(&P1, NULL, (void *)produce_item, NULL);
  pthread_create(&C1, NULL, (void *)consume_item, NULL);

  pthread_join(P1, NULL);
  pthread_join(C1, NULL);

  pthread_mutex_destroy(&mutex);
  sem_destroy(&empty);
  sem_destroy(&full);

  return 0;
}