// ravindar
// CS20B1085
// Lab Exercise 10: C program to implement Simple Machine Code Generator.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char var[100];
    int alive;
} MCGEN;
MCGEN arr[100];

void substring(char e[], int st, int end)
{
    int i, j = 0;
    char d[10] = "";
    for (i = st; i < end; i++)
    {
        d[j++] = e[i];
        d[j] = '0';
    }

    strcpy(e, d);
}
int getMCGENer(char var[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (arr[i].alive == 0)
        {
            strcpy(arr[i].var, var);
            break;
        }
    }
    return (i);
}
void getvar(char e[], char v[])
{
    int i, j = 0;
    char var[10] = "";
    for (i = 0; e[i] != '\0'; i++)
        if (isalpha(e[i]))
            var[j++] = e[i];
        else
            break;
    strcpy(v, var);
}
int main()
{
    char basic[10][10], var[10][10], fstr[10], op;
    int i, j, k, reg, vc = 0, flag = 0;
    int count = 0;
    printf("\nEnter the Three Address Code:\n");
    for (i = 0;; i++)
    {
        gets(basic[i]);
        count++;
        if (strcmp(basic[i], "exit") == 0)
            break;
    }
    printf("\nThe Equivalent Assembly Code is:\n");
    for (j = 0; j < count - 1; j++)
    {
        getvar(basic[j], var[vc++]);
        strcpy(fstr, var[vc - 1]);
        substring(basic[j], strlen(var[vc - 1]) + 1, strlen(basic[j]));
        getvar(basic[j], var[vc++]);
        reg = getMCGENer(var[vc - 1]);
        if (arr[reg].alive == 0)
        {
            printf("\nMov R%d,%s", reg, var[vc - 1]);
            arr[reg].alive = 1;
        }
        op = basic[j][strlen(var[vc - 1])];
        substring(basic[j], strlen(var[vc - 1]) + 1, strlen(basic[j]));
        getvar(basic[j], var[vc++]);
        switch (op)
        {
        case '+':
            printf("\nAdd");
            break;
        case '-':
            printf("\nSub");
            break;
        case '*':
            printf("\nMul");
            break;
        case '/':
            printf("\nDiv");
            break;
        }
        flag = 1;
        for (k = 0; k <= reg; k++)
        {
            if (strcmp(arr[k].var, var[vc - 1]) == 0)
            {
                printf("R%d,R%d", k, reg);
                printf("\nMov %s,R%d", fstr, reg);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf(" %s,R%d", var[vc - 1], reg);
            printf("\nMov %s,R%d", fstr, reg);
        }
        strcpy(arr[reg].var, var[vc - 3]);
    }
    return 0;
}