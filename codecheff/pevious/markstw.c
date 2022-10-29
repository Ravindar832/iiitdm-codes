#include <stdio.h>

int main(void)
{
    int n;
    int x, y;
    int i;
    
    printf("enter the number of sets");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the marks of x and y ");
        scanf("%d %d", &x, &y);

        if (x >= 2*y)
        {
        
            printf("yes");
        }
        if(x < 2*y )
        {
           printf("no"); 
        }
    }

    // your code goes here
    return 0;
}