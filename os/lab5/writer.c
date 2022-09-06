
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#define SHMSIZE 85
int main()
{
    int c, n;
    int shimd;
    key_t key;
    int *shm, *s;
    int x;

    key = 1085;

    if ((shimd = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0)
    {
        printf("Error in shimd\n");
        exit(1);
    }

    if ((shm = shmat(shimd, NULL, 0)) == (int *)-1)
    {
        printf("Error in shmat\n");
        exit(1);
    }

    s = shm;

    printf("Enter the range of the numbers ");
    scanf("%d", &n);
    for (c = 1; c <= n; c++)
    {
        printf("enter the elements to send :");
        scanf("%d", &x);
        *s++ = x;
        *s = 0;
    }
    shmdt(shm);

    return 0;
}