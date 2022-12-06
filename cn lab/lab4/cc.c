#include<stdio.h>
#include<string.h>

int main()
{
    int no_of_frames;
    char data[1000],str1[1000],str2[1000];
    printf("Enter data: ");
    scanf("%s", data);
    int len = strlen(data);
    int size;
    printf("Enter frame size: ");
    scanf("%d",&size);
    if(len % (size - 1) == 0)
    {
        no_of_frames = (len/(size - 1));
    }
    else
    {
        no_of_frames = (len/(size - 1)) + 1;
    }
    int j=0;
    for(int i = 0;i < (len + no_of_frames);i++)
    {
        if(i % size == 0)
        {
            if((len-j) < size)
            {
                str1[i]=(char)(48+len-j+1);
            }
            else
            {
                str1[i]=(char)(48+size);
            }
        }
        else
        {
            str1[i]=data[j];
            j=j+1;
        }
    }
    printf("The data bits after stuffing is : ");
    for(int i=0;i<len+no_of_frames;i++)
    {
        printf("%c",str1[i]);
    }
    j=0;
    for(int i=0;i<(len+no_of_frames);i++)
    {
        if(i%size != 0)
        {
            str2[j] = str1[i];
            j=j+1;
        }
    }
    printf("\nThe data bits after destuffing is : ");
    for(int i=0;i<j;i++)
    {
        printf("%c",str2[i]);
    }

    return 0;
}