
// cs20b1085 gugulothu ravindar
// lab5 assignment

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define size1 20
#define size2 30
#define size3 30
#define size 20

struct Token
{
    char a[size1];
    char b[size2];
    char c[size3];
};

int main()
{
    struct Token T[size];
    FILE *fp = fopen("file2.c", "r");
    char temp[30], temp1[30];
    char keywords[7][30] = {"#include", "int", "<stdio.h>", "main", "float", "char", "return"};
    char ch;
    int rows = 7, cols = 0;
    int flag1 = 0, flag = 0, flag2 = 0;
    int l = 0, x = 0, i = 0, t = 0, len1;

    if (fp == NULL)
    {
        printf("Unable to Open");
    }
    else
    {
        do
        {
            ch = fgetc(fp);

            if (ch != ')' && ch != '(' && ch != '{' && ch != '}' && ch != ';' && ch != ':' && ch != '=')
            {
                temp[i] = ch;
                i++;
            }
            
            if (strcmp(temp, "int") == 0 || strcmp(temp, "float") == 0 || strcmp(temp, "char") == 0)
            {
                for(l=0; l<i; l++)
                {
                    temp1[l] = temp[l];
                }
                len1 = i;
                temp1[l] = '\0';
                flag2 = 1;
            }
            if (ch == '=')
            {
                strcpy(temp1, temp);
                flag1 = 1;
                flag = 1;
            }

            if (ch == ';')
            {
                temp[i] = '\0';
                if (flag1 == 1)
                {
                    for (x = 0; x < t; x++)
                    {
                        if (strcmp(temp1, T[x].a) == 0)
                        {
                            break;
                        }
                    }
                    for (l = 0; l < i; l++)
                    {
                        T[x].c[l] = temp[l];
                    }
                    T[x].c[l] = '\0';
                }
                else
                {
                    for (x = 0; x < i; x++)
                    {
                        T[t].a[x] = temp[x];
                    }
                    T[t].a[x] = '\0';

                    if(flag2 == 1)
                    {
                        for(l=0; l<len1; l++)
                        {  
                            
                            T[t].b[l] = temp1[l];
                        }
                        T[t].b[l] = '\0';
                    
                        flag2 = 0;
                    }
                    t++;
                }
                flag = 1;
                flag1 = 0;
            }

            if (flag == 0)
            {
                for (int j = 0; j < rows; j++)
                {
                    if (strcmp(temp, keywords[j]) == 0)
                    {
                        flag = 1;
                        break;
                    }
                    flag = 0;
                }
            }

            if (flag == 1)
            {
                for (int j = 0; j < i; j++)
                {
                    temp[j] = '\0';
                }
                i = 0;
                flag = 0;
            }

        } while (ch != EOF);
        for(l=0; l<t-1; l++)
        {
            printf(" %s - %s - %s   ",T[l].a ,T[l].b, T[l].c);
        }
    }
}