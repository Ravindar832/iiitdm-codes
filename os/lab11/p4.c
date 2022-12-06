#include <stdio.h>
#include <stdlib.h>

int n = 4, m = 3, i, j, k;
int Allocation[4][3];
int need[4][3];
int max[4][3];
int total_avaliable[3], avaliable[3];
int x = 0, y = 0, z = 0;

void cal();

void request();

int main()
{
    printf("Enter the Allocation matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf("%d", &Allocation[i][j]);
    }
    printf("Enter the Max need matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }
    printf("Enter the Total Avalible array: \n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &total_avaliable[i]);
    }
    cal();
    request();
    return 0;
}

void cal()
{
    int x = 0, y = 0, z = 0;
    for (i = 0; i < n; i++)
    {
        x += Allocation[i][0];
        y += Allocation[i][1];
        z += Allocation[i][2];
    }
    avaliable[0] = total_avaliable[0] - x;
    avaliable[1] = total_avaliable[1] - y;
    avaliable[2] = total_avaliable[2] - z;

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - Allocation[i][j];
    }
    printf("Need Matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    y = 0;
    for (k = 0; k < 4; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avaliable[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avaliable[y] += Allocation[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            printf("------------------ NOT SAFE ------------------");
            break;
        }
    }

    if (flag == 1)
    {
        printf("------------------ SAFE ------------------\n");
        for (i = 0; i < n - 1; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d", ans[n - 1]);
    }
}

void request()
{
    int c, pid, request[100][100], i;
    while (1)
    {
        printf("\n Do you want make an additional request for any of the process ? (1=Yes|0=No)");
        scanf("%d", &c);
        if (c == 1)
        {
            printf("\n Enter process number : ");
            scanf("%d", &pid);
            printf("\n Enter additional request : \n");
            for (i = 0; i < m; i++)
            {
                printf(" Request for resource %d : ", i + 1);
                scanf("%d", &request[0][i]);
            }
            for (i = 0; i < m; i++)
            {
                if (request[0][i] > need[pid][i])
                {
                    printf("\n NOT SAFE \n");
                    exit(0);
                }
            }
            for (i = 0; i < m; i++)
            {
                avaliable[i] -= request[0][i];
                Allocation[pid][i] += request[0][i];
                need[pid][i] -= request[0][i];
            }
            cal();
        }
        else
        {
            exit(0);
        }
    }
}