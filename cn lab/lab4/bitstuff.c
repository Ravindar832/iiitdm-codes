
#include<stdio.h>
#include<string.h>
int main()
{
    int a[30],b[40],i,j,k,count,n;
    printf("Enter frame size :");
    scanf("%d",&n);
    printf("Enter the frame in the form of 0 and 1 :");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    i=0;
    count=1;                         
    j=0;
    while(i<n)                       //1101 0111   1101        0111        1110      1011      1111      10 
    {
        if(a[i]==1)                  //1101 0111   1 0 101       0111        1110      1011      1111      10
        {                          
            b[j]=a[i];               
            for(k=i+1; a[k]==1 && k<n && count<6; k++)
            {
                j++;
                b[j]=a[k];
                count++;
                if(count==6)
                {
                    j++;
                    b[j]=0;
                }
                i=k;
            }
        }
        else
        {
            b[j]=a[i];
        }
        i++;
        j++;
    }
    printf("After Bit Stuffing :");
    for(i=0; i<j; i++)
        printf("%d",b[i]);
    return 0;
}