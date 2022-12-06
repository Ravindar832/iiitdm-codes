//cs20b1085 gugulothu ravindar
/*Implement the reader-writer problem’s solution using semaphore. Use one writer thread and multiple reader threads.
 Also, clearly define the reader() function and writer() function. 
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t s1;
pthread_mutex_t mutex;
int count = 1;
int numreader = 0;

void *writer(void *writer_no)
{   
    sem_wait(&s1);
    
    printf("Writer %d modified count to %d\n",(*((int *)writer_no)),count);
    sem_post(&s1);

}
void *reader(void *reader_no)
{   
    // Reader acquire the lock before modifying numreader
    pthread_mutex_lock(&mutex);
    numreader++;
    if(numreader == 1) {
        sem_wait(&s1); // If this id the first reader, then it will block the writer
    }
    pthread_mutex_unlock(&mutex);
    // Reading Section
    count = count*2;
    printf("Reader %d: read count as %d\n",*((int *)reader_no),count);

    // Reader acquire the lock before modifying numreader
    pthread_mutex_lock(&mutex);
    numreader--;
    if(numreader == 0) {
        sem_post(&s1); // If this is the last reader, it will wake up the writer.
    }
    pthread_mutex_unlock(&mutex);
}

int main()
{   
    int n;
    printf("enter the number of readers   : ");
    scanf("%d",&n);
    pthread_t read[n],write[1];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&s1,0,1);
    int a[n];
    for(int i = 0; i < n; i++) {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }
    
    pthread_create(&write[1], NULL, (void *)writer, (void *)&a[1]);
    

    for(int i = 0; i < n; i++) {
        pthread_join(read[i], NULL);
    }
    
    pthread_join(write[1], NULL);
    

    pthread_mutex_destroy(&mutex);
    sem_destroy(&s1);

    return 0;
    
}