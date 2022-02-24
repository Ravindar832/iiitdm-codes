// Bubble Sort

#include<stdio.h>

int main()
{

  int n,i,temp,j ;
  printf("\n Enter array size \n");
  scanf("%d", &n);

  int a[n];
  
  printf("\n Enter %d integers \n", n);
  for(i=0; i<n; ++i)
   scanf("%d", &a[i]);



 //proc: swap a[j] with a[j+1] if a[j]>a[j+1]
  
 for(i=0; i<n; ++i)
   for(j=0; j< (n-1-i); ++j)   // when i=0,  j=0 to n-2; when i=1, j=0 to n-3..... when i=n-1, j j=0 to n-1-(n-1)=0
    if(a[j]>a[j+1])
    {
     temp=a[j];
     a[j]=a[j+1];
     a[j+1]=temp;
    } 




printf("\n The Sorted array: \n");
for(i=0; i<n; ++i)
   printf(" %d ", a[i]);



  return(0);
}
