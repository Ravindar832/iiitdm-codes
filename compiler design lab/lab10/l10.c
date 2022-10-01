// Lab Exercise 10:

// C program to implement Simple Machine Code Generator.

// ALGORITHM:

// 1. Start
// 2. Get address code sequence.
// 3. Determine current location of 3 using address (for 1st operand).
// 4. If current location not already exist generate move (B,O).
// 5. Update address of A(for 2nd operand).
// 6. If current value of B and () is null,exist.
// 7. If they generate operator () A,3 ADPR.
// 8. Store the move instruction in memory
// 9. Stop

// C program to implement Simple Code Generator.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
// #include<aio.h>
typedef struct
{
    char var[10];
    int alive;
} regist;
regist preg[10];
void substring(char exp[], int st, int end)
{
    int i, j = 0;
    char dup[10] = "";
    for (i = st; i<10; i++)
        dup[j++] = exp[i];
    dup[j] = '0';
    strcpy(exp, dup);
}
int getregister(char var[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (preg[i].alive == 0)
        {
            strcpy(preg[i].var, var);
            break;
        }
    }
    return (i);
}
void getvar(char exp[], char v[])
{
    int i, j = 0;
    char var[10] = "";
    for (i = 0; exp[i] != '\0'; i++)
        if (isalpha(exp[i]))
            var[j++] = exp[i];
        else
            break;
    strcpy(v, var);
}
void main()
{
    char basic[10][10], var[10][10], fstr[10], op;
    int i, j, k, reg, vc, flag = 0; 
    int n;
    printf("\nEnter the Three Address Code:\n");
    for (i = 0;i<10; i++)
    {
        // gets(basic[i]);
        scanf("%s",&basic[i]);
        if (strcmp(basic[i], "exit") == 0)
            break;
    }
    printf("\nThe Equivalent Assembly Code is:\n");
    for (j = 0; j < reg; j++)
    {
        getvar(basic[j], var[vc++]);
        strcpy(fstr, var[vc - 1]);
        substring(basic[j], strlen(var[vc - 1]) + 1, strlen(basic[j]));
        getvar(basic[j], var[vc++]);
        reg = getregister(var[vc - 1]);
        if (preg[reg].alive == 0)
        {
            printf("\nMov R%d,%s", reg, var[vc - 1]);
            preg[reg].alive = 1;
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
            if (strcmp(preg[k].var, var[vc - 1]) == 0)
            {
                printf("R%d, R%d", k, reg);
                preg[k].alive = 0;
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf(" %s,R%d", var[vc - 1], reg);
            printf("\nMov %s,R%d", fstr, reg);
        }
        strcpy(preg[reg].var, var[vc - 3]);
    }
}

// INPUT:

// a=b+C
// C=a*C
// exit

// OUTPUT

// The equivalent assembly code is:

// Move R0,b
// Add c,R0
// Mov a,R0
// Mov R1,a
// Mul c,R1
// Mov c,R1