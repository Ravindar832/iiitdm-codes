// ravindar
// CS20B1085
/*
CD Lab exercise 11:

        Write a C program to do a simple Shift Reduce Passing.
*/

#include <stdio.h>
#include <string.h>

int k = 0, z = 0, i = 0, j = 0, c = 0;
char a[16], ac[20], stack[15], action[10];
void check();
int main()
{

    printf("GRAMMAR is \n S->S+S \n S->S*S \n S->(S) \n S->id");
    printf("\nEnter input string: ");
    gets(a);
    c = strlen(a);
    strcpy(action, "SHIFT->");
    printf("Stack \t\t\t  Input \t\t\t Action");
    for (k = 0, i = 0; j < c; k++, i++, j++)
    {
        if (a[j] == 'i' && a[j + 1] == 'd')
        {
            stack[i] = a[j];
            stack[i + 1] = a[j + 1];
            stack[i + 2] = '\0';
            a[j] = ' ';
            a[j + 1] = ' ';
            printf("\n$%s\t\t\t%s$\t\t\t%sid", stack, a, action);
            check();
        }
        else
        {
            stack[i] = a[j];
            stack[i + 1] = '\0';
            a[j] = ' ';
            printf("\n$%s\t\t\t%s$\t\t\t%ssymbols", stack, a, action);
            check();
        }
    }
}
void check()
{
    strcpy(ac, "REDUCE TO S");
    for (z = 0; z < c; z++)
        if (stack[z] == 'i' && stack[z + 1] == 'd')
        {
            stack[z] = 'S';
            stack[z + 1] = '\0';
            printf("\n$%s\t\t\t%s$\t\t\t%s", stack, a, ac);
            j++;
        }
    for (z = 0; z < c; z++)
        if (stack[z] == 'S' && stack[z + 1] == '+' && stack[z + 2] == 'S')
        {
            stack[z] = 'S';
            stack[z + 1] = '\0';
            stack[z + 2] = '\0';
            printf("\n$%s\t\t\t%s$\t\t\t%s", stack, a, ac);
            i = i - 2;
        }
    for (z = 0; z < c; z++)
        if (stack[z] == 'S' && stack[z + 1] == '*' && stack[z + 2] == 'S')
        {
            stack[z] = 'S';
            stack[z + 1] = '\0';
            stack[z + 1] = '\0';
            printf("\n$%s\t\t\t%s$\t\t\t%s", stack, a, ac);
            i = i - 2;
        }
    for (z = 0; z < c; z++)
        if (stack[z] == '(' && stack[z + 1] == 'S' && stack[z + 2] == ')')
        {
            stack[z] = 'S';
            stack[z + 1] = '\0';
            stack[z + 1] = '\0';
            printf("\n$%s\t\t\t%s$\t\t\t%s", stack, a, ac);
            i = i - 2;
        }
}