#include <stdio.h>
#include <stdlib.h>
int processes = 4, resources = 3, i, j, k;
int max[4][3];
int alloc[4][3];
int need[3][3];
int avail[3];
int x = 0, y = 0, z = 0;
int avaliable[3];

void input();

void show();

void request();

void cal();

int main()
{
    int i, j;
    printf(" Banker's Algorithm\n");
    input();
    show();
    cal();
    request();
    return 0;
}

void input()
{
    int i, j;
    printf("Enter the no of Processes\t");
    scanf("%d", &processes);
    printf("Enter the no of resources \t");
    scanf("%d", &resources);
    printf("Enter the Max Matrix\n");
    for (i = 0; i < processes; i++)
    {
        for (j = 0; j < resources; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the Allocation Matrix\n");
    for (i = 0; i < processes; i++)
    {
        for (j = 0; j < resources; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the available Resources\n");
    for (j = 0; j < resources; j++)
    {
        scanf("%d", &avail[j]);
    }
}

void show()
{
    int i, j;
    printf("Process\t Allocation\t Max\t Available\t");
    for (i = 0; i < processes; i++)
    {
        printf("\nP%d\t ", i + 1);
        for (j = 0; j < resources; j++)
        {
            printf("%d ", alloc[i][j]);
        }
        printf("\t");
        for (j = 0; j < resources; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("\t");
        if (i == 0)
        {
            for (j = 0; j < resources; j++)
                printf("%d ", avail[j]);
        }
    }
}

void cal()
{
    int x = 0, y = 0, z = 0;
    for (i = 0; i < processes; i++)
    {
        x += alloc[i][0];
        y += alloc[i][1];
        z += alloc[i][2];
    }
    avaliable[0] = avail[0] - x;
    avaliable[1] = avail[1] - y;
    avaliable[2] = avail[2] - z;

    int f[processes], ans[processes], ind = 0;
    for (k = 0; k < processes; k++)
    {
        f[k] = 0;
    }
    int need[processes][resources];
    for (i = 0; i < processes; i++)
    {
        for (j = 0; j < resources; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    printf("\nThe need Table:\n");
    for (i = 0; i < processes; i++)
    {
        for (j = 0; j < resources; j++)
        {
            printf("\t%d", need[i][j]);
        }
        printf("\n");
    }
    // int y = 0;
    for (k = 0; k < 4; k++)
    {
        for (i = 0; i < processes; i++)
        {
            if (f[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < resources; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < resources; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < resources; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            printf("The following system is not safe");
            break;
        }
    }

    if (flag == 1)
    {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < resources - 1; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d", ans[resources - 1]);
    }
}
void request()
{
        int c, pid, request[100][100], B[100][100], i;
        printf("\n Do you want make an additional request for any of the process ? (1=Yes|0=No)");
        scanf("%d", &c);
        if (c == 1)
        {
            printf("\n Enter process number : ");
            scanf("%d", &pid);
            printf("\n Enter additional request : \n");
            for (i = 0; i < resources; i++)
            {
                printf(" Request for resource %d : ", i + 1);
                scanf("%d", &request[0][i]);
            }
            for (i = 0; i < resources; i++)
            {
                if (request[0][i] > need[pid][i])
                {
                    printf("\n the process NOT SAFE \n");
                    exit(0);
                }
            }
            for (i = 0; i < resources; i++)
            {
                avail[i] -= request[0][i];
                alloc[pid][i] += request[0][i];
                need[pid][i] -= request[0][i];
            }
            cal();
        }
        else
        {
            exit(0);
        }
}