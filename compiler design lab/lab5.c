#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char symbols, attribute1, attribute2;
    char ch;
    fp = fopen("file2.c", "r");
    if (fp == NULL)
    {
        printf("error file");
    }
    do{
    ch = fgetc(fp);
    if (ch == )
    {
        /* code */
    }
    
} 
while( ch != EOF);  
fclose(fp);
  printf("%c",ch);
}