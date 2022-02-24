#include<stdio.h>

void rprint(int a[], int n);
int main()
{

  int a[]={1,2,3,4,5};
  
  
  rprint(a, 5);

  return(0);
}


void rprint(int a[], int n)
{
   if(n==0)
     return ;
  else
  {
    printf(" %d ", a[n-1]);
    rprint(a, n-1);
  }

}

  
  
  
  
