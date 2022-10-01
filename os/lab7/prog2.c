/* Write a program where you create 3 threads. Consider two global matrix M1 and M2 of size 3 x 3.
Perform addition, subtraction and multiplication in individual thread and store in matrix A[3][3], S[3][3] and M[3][3].
Print the individual matrix values (M1 and M2) and computed matrix of addition, subtraction, multiplication operation in the main function .
Once all thread process will be completed, then only main function will execute. */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Value depend on System core
#define CORE 3

// Maximum matrix size
#define MAX 3

// Maximum threads is equal to total core of system
pthread_t thread[CORE * 2];
int mat_A[MAX][MAX], mat_B[MAX][MAX], sum[MAX][MAX], sub[MAX][MAX];

// Addition of a Matrix
void *addition(void *arg)
{

    int i, j;
    int core = (int)arg;

    // Each thread computes 1/4th of matrix addition
    for (i = core * MAX / 4; i < (core + 1) * MAX / 4; i++)
    {

        for (j = 0; j < MAX; j++)
        {

            // Compute Sum Row wise
            sum[i][j] = mat_A[i][j] + mat_B[i][j];
        }
    }
}

// Subtraction of a Matrix
void *subtraction(void *arg)
{

    int i, j;
    int core = (int)arg;

    // Each thread computes 1/4th of matrix subtraction
    for (i = core * MAX / 4; i < (core + 1) * MAX / 4; i++)
    {

        for (j = 0; j < MAX; j++)
        {

            // Compute Subtract row wise
            sub[i][j] = mat_A[i][j] - mat_B[i][j];
        }
    }
}

int main()
{
     
    int mat_A[10][10], i, j,step = 0;
    int mat_B[10][10];
    printf("Enter your matrix\n");
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
        {
            scanf("%d", &mat_A[i][j]);
        }
    
    // Displaying mat_A
    printf("\nMatrix A:\n");

    for (i = 0; i < MAX; i++)
    {

        for (j = 0; j < MAX; j++)
        {

            printf("%d ", mat_A[i][j]);
        }

        printf("\n");
    }

    printf("Enter your matrix\n");
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
        {
            scanf("%d", &mat_B[i][j]);
        }
    

    // Displaying mat_B
    printf("\nMatrix B:\n");

    for (i = 0; i < MAX; i++)
    {

        for (j = 0; j < MAX; j++)
        {

            printf("%d ", mat_B[i][j]);
        }

        printf("\n");
    }

    // Creating threads equal
    // to core size and compute matrix row
    for (i = 0; i < CORE; i++)
    {

        pthread_create(&thread[i], NULL, &addition, (void *)step);
        pthread_create(&thread[i + CORE], NULL, &subtraction, (void *)step);
        step++;
    }

    // Waiting for join threads after compute
    for (i = 0; i < CORE * 2; i++)
    {

        pthread_join(thread[i], NULL);
    }

    // Display Addition of mat_A and mat_B
    printf("\n Sum of Matrix A and B:\n");

    for (i = 0; i < MAX; i++)
    {

        for (j = 0; j < MAX; j++)
        {

            printf("%d   ", sum[i][j]);
        }

        printf("\n");
    }

    // Display Subtraction of mat_A and mat_B
    printf("\n Subtraction of Matrix A and B:\n");

    for (i = 0; i < MAX; i++)
    {

        for (j = 0; j < MAX; j++)
        {

            printf("%d   ", sub[i][j]);
        }

        printf("\n");
    }

    return 0;
}