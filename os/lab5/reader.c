#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
int SHMSIZE = 85;

int main()
{
    int shimd;
    key_t key;
    int *shm, *s;
    // int SHMSIZE = 85;
    key = 1085;

    if ((shimd = shmget(key, SHMSIZE, 0666)) < 0)
    {
        printf("Error in shimd\n");
        exit(1);
    }

    if ((shm = shmat(shimd, NULL, 0)) == (int *)-1)
    {
        printf("Error in shmat\n");
        exit(1);
    }
    // printf("Shared Memory ID: %d\n", shimd);

    for (s = shm; *s != 0; s++)
    {
        if (*s % 2 == 0)
        {
            printf("%d  Even\n", *s);
        }

        else
        {
            printf("%d  Odd\n", *s);
        }
    }
    printf("\n");
    printf("shm%d", shimd);
    shmdt(shm);
    shmctl(shimd, IPC_RMID, NULL);
    return 0;
}