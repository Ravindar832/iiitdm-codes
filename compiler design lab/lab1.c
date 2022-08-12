#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int main()
{
FILE *fp;
char ch;
fp = fopen("file1.c", "r");
if (fp==NULL)
{
   printf("error file");
}

do{
    ch = fgetc(fp);
    if( isgraph(ch) ) putchar (ch);
} 
while( ch != EOF);  
fclose(fp);
  printf("%c",ch);
  
}