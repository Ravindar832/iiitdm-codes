#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

#define buff 85

int main()
{
    char *shm;
    char str[buff];
    int shmid;

    shmid = shmget((key_t)8185, 1024, 0666 | IPC_CREAT);

    shm = shmat(shmid, NULL, 0);
    printf("Enter the message : ");
    fgets(str, buff, stdin);

    strcpy(shm, str);
    while (*shm != '0')
    {
        sleep(15);
    }

    char *shm2;
    int shmid2;

    shmid2 = shmget((key_t)6699, 1024, 0666);
    shm2 = shmat(shmid2, NULL, 0);

    printf("Message received from the receiver is : %s\n", (char *)shm2);

    return 0;
}