#include <stdio.h>

int main(void)
{
    int n;
    int x;
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {

        scanf("%d", &x);
        c(x);
    }

    // your code goes here
    return 0;
}
void c(int x)
{
    if (x <= 98)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
}
