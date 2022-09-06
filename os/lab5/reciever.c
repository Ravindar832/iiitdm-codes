#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

#define buff 85

int main()
{
    char *shm;
    int shmid;

    shmid = shmget((key_t)8185, 1024, 0666);
    shm = shmat(shmid, NULL, 0);

    printf("Message received from the sender.c is : %s\n", (char *)shm);

    *shm = '0';

    char *shm2;

    char str2[buff];
    int shmid2;

    shmid2 = shmget((key_t)6699, 1024, 0666 | IPC_CREAT);
    shm2 = shmat(shmid2, NULL, 0);
    printf("Enter message from receiver : ");
    fgets(str2, buff, stdin);

    strcpy(shm2, str2);

    return 0;
}