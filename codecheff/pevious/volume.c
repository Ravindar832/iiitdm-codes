// volume of tv

#include <stdio.h>

int main(void)
{
    int n;
    int x, y;
    int i;
    int difference;
    printf("enter the number of sets");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the volumes of x and y ");
        scanf("%d %d", &x, &y);

        if (x > y)
        {
            difference = x - y;
            printf("difference is %d", difference);
        }
        else
        {
            difference = y - x;
            printf("difference is %d", difference); /* code */
        }
    }

    // your code goes here
    return 0;
}