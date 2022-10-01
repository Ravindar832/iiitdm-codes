// Lab Exercise 8:

// Write a C program to simulate lexical analyzer for validating operators

// Instruction:

// Read the given input.
// If the given input matches with any operator symbol.
// Then display in terms of words of the particular symbol.
// Else print not a operator.

//cs2b1085 gugulothu ravindar

#include <stdio.h>
#include <stdlib.h>

void main()
{
    char s[5];
    char k;
    printf("\n Enter any operator:");
    // gets(s);
    scanf("%s",&s[k]);
    switch (s[0])
    {
    case '>':
        if (s[1] == '=')
            printf("\n Greater than or equal");
        else
            printf("\n Greater than");
        break;
    case '<':
        if (s[1] == '=')
            printf("\n Less than or equal");
        else
            printf("\nLess than");
        break;
    case '=':
        if (s[1] == '=')
            printf("\nEqual to");
        else
            printf("\nAssignment");
        break;
    case '!':
        if (s[1] == '=')
            printf("\nNot Equal");
        else
            printf("\n Bit Not");
        break;
    case '&':
        if (s[1] == '&')
            printf("\nLogical AND");
        else
            printf("\n Bitwise AND");
        break;
    case '|':
        if (s[1] == '|')
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
        printf("Modulus");
        break;
    default:
        printf("\n Not a operator");
    }
    // getch();
}