// ravindar
// CS20B1085
// Lab Exercise 8: Write a C program to simulate lexical analyzer for validating operators

#include <stdio.h>

int main()
{
    char str[5];
    printf("\n Enter any operator:");
    gets(str);
    switch (str[0])
    {
    case '>':
        if (str[1] == '=')
            printf("\n Greater than or equal");
        else if (str[1] == '>')
            printf("\n Right shift operator");
        else
            printf("\n Greater than");
        break;
    case '<':
        if (str[1] == '=')
            printf("\n Less than or equal");
        else if (str[1] == '<')
            printf("\n Left shift operator");
        else
            printf("\nLess than");
        break;
    case '=':
        if (str[1] == '=')
            printf("\nEqual to");
        else
            printf("\nAssignment");
        break;
    case '!':
        if (str[1] == '=')
            printf("\nNot Equal");
        else
            printf("\n Bit Not");
        break;
    case '&':
        if (str[1] == '&')
            printf("\nLogical AND");
        else
            printf("\n Bitwise AND");
        break;
    case '|':
        if (str[1] == '|')
            printf("\nLogical OR");
        else
            printf("\nBitwise OR");
        break;
    case '+':
        printf("\n Addition");
        break;
    case '-':
        printf("\nSubstraction");
        break;
    case '*':
        printf("\nMultiplication");
        break;
    case '/':
        printf("\nDivision");
        break;
    case '%':
        printf("\n Modulus");
        break;
    case '^':
        printf("\n XOR operator");
        break;
    case '~':
        printf("\n BitWise Complement");
        break;
    default:
        printf("\n Not a operator");
    }

    return 0;
}