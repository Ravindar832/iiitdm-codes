
#include <stdio.h>
int main()
{

    int k;
    printf("eter the k value");
    scanf("%d",&k);
    int count = 0; 
    for (int i = 1; i < 100; i++)
        for (int j = 1; j < 100; j++)
            if ((i + j) == k)
                count++;
                printf("%d",count);       
    return 0;
}