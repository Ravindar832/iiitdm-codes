#include<stdio.h>             
#include<string.h> 
#include<ctype.h>

void Receiver_end(char a[], int n)
{
    char b[100];
    int i, j;
    j=0;
    for(i=1;i<n-1;i++)
    {
        if(a[i]=='f' || a[i]=='F')
        {
            if(a[i] == 'f')
            {
                i++;
                b[j]=a[i];
            }
            else if(a[i] == 'F')
            {
                i++;
                b[j]=a[i];
            }

        }
        else if(a[i]=='e' || a[i]=='E')
        {
            if(a[i] == 'e')
            {
                
                i++;
                b[j]=a[i];
            }
            else if(a[i] == 'E')
            {
                
                i++;
                b[j]=a[i];
            }
        }
        else
            b[j]=a[i];
             j++;
    }
    printf("\nThe final bits after removing the stuffed bit is : ");
    for (i = 0; i < j; i++)
    {
        printf("%c", b[i]);
    }
}

int main()
{
    char a[20],b[20];
    int i,n,j;
    char f,s;
    printf("\nEnter the characters in frame : ");
    gets(a);
    n = strlen(a);
    printf("FRAME : ");
    for(i=0;i<n;i++)
    {
        printf("%c",a[i]);
    }
    j=0;
    b[j] = 'f';
    j++;
    for(i=0;i<n;i++)
    {
        if(a[i]=='f' || a[i]=='F')
        {
            if(a[i] == 'f')
            {
                b[j]='e';
                j++;
                b[j]=a[i];
            }
            else if(a[i] == 'F')
            {
                b[j]='E';
                j++;
                b[j]=a[i];
            }

        }
        else if(a[i]=='e' || a[i]=='E')
        {
            if(a[i] == 'e')
            {
                b[j]='e';
                j++;
                b[j]=a[i];
            }
            else if(a[i] == 'E')
            {
                b[j]='E';
                j++;
                b[j]=a[i];
            }
        }
        else
            b[j]=a[i];
             j++;
    }
    b[j] = 'f';
    j++;
    printf("\nRESULT ");
    for(i=0;i<j;i++)
    {
        printf("%c",b[i]);
    }
    Receiver_end(b, j);
}