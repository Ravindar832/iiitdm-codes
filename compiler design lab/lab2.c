/* C program to remove comennnts from a string */
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int main()
{
    FILE *fp1;
    int flag=0;
    char ch;
    fp1=fopen("file1.c","r");
    if(fp1==NULL)
    {
        printf("Error while opening a file for reading");
        return 0;
    }
    
    while((ch=fgetc(fp1))!=EOF)
    {
        if((ch=='/')&&(flag==0))
        {
            flag=1;
            continue;
        }
        else if((ch=='/')&&(flag==1))
        {
            flag=2;
            continue;
        }
        else if((ch=='*')&&(flag==1))
        {
            flag=3;
            continue;
        }
        if(flag==2)
        {
            if(ch=='n')
            {
              flag=0;
            }
            continue;
        }
        if(flag==3)
        {
            if(ch=='*')
            {
              flag=4;
            }
            continue;
        }
        if(flag==4)
        {
            if(ch=='/')
            {
              flag=0;
            }
            continue;
        }
        if(flag==0)
        {
 
            if((ch==10)||(ch==13))
            {
                continue;
            }
            else if((ch!=' '))
            {
               fputc(ch,fp1);
            }

            printf("%c",ch);
        }
    }
    fclose(fp1);
    
    return 0;
}