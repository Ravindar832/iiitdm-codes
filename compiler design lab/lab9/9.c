// ravindar
// CS20B1085
// Lab Exercise 9: Write a C program for constructing of LL (1) parsing.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[20], stack[20];
int main()
{
    int S[5][6] = {2, 0, 0, 2, 0, 0, 0, 3, 0, 0, 1, 1, 2, 0, 0, 2, 0, 0, 0, 1, 3, 0, 1, 1, 1, 0, 0, 3, 0, 0};
    char m[5][6][3] = {"tb", "", "", "tb", "", "", "", "+tb", "", "", "n",
                       "n", "fc", "", "", "fc", "", "", "", "n", "*fc", "", "n", "n", "i", "", "", "(e)", "", ""};
    int i, j, k, n, s_1, s_2;
    printf("\n Enter the input string: ");
    scanf("%s", s);
    strcat(s, "$");
    n = strlen(s);
    stack[0] = '$';
    stack[1] = 'e';
    i = 1;
    j = 0;
    printf("\nStack\t\tInput\n");
    printf("________________________\n");
    while ((stack[i] != '$') || (s[j] != '$'))
    {
        if (stack[i] == s[j])
        {
            i--;
            j++;
            for (k = 0; k <= i; k++)
                printf("%c", stack[k]);
            printf("\t\t");
            for (k = j; k <= n; k++)
                printf("%c", s[k]);
            printf("\n");
        }
        switch (stack[i])
        {
        case 'e':
            s_1 = 0;
            break;
        case 'b':
            s_1 = 1;
            break;
        case 't':
            s_1 = 2;
            break;
        case 'c':
            s_1 = 3;
            break;
        case 'f':
            s_1 = 4;
            break;
        }
        switch (s[j])
        {
        case 'i':
            s_2 = 0;
            break;
        case '+':
            s_2 = 1;
            break;
        case '*':
            s_2 = 2;
            break;
        case '(':
            s_2 = 3;
            break;
        case ')':
            s_2 = 4;
            break;
        case '$':
            s_2 = 5;
            break;
        }
        if (m[s_1][s_2][0] == '\0')
        {
            printf("\nERROR");
            exit(0);
        }
        else if (m[s_1][s_2][0] == 'n')
            i--;
        else if (m[s_1][s_2][0] == 'i')
            stack[i] = 'i';
        else
        {
            for (k = S[s_1][s_2] - 1; k >= 0; k--)
            {
                stack[i] = m[s_1][s_2][k];
                i++;
            }
            i--;
        }
        for (k = 0; k <= i; k++)
            printf("%c", stack[k]);
        printf("\t\t");
        for (k = j; k <= n; k++)
            printf("%c", s[k]);
        printf("\n");
    }
    printf("\nSUCCESS");
    return 0;
}