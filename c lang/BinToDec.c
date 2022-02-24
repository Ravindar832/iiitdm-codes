//Deci to binary

#include<stdio.h>
#include<math.h>
int main()
{
  int n,q,r,i, last, Dec;
  
  int a[100];
 

 //Input
  printf("\n Enter the number of bits  \n");
  scanf("%d", &n); 

 
  printf("\n Enter %d bits \n ", n);
  
  for(i=0; i<n; ++i)
  {
    scanf("%d", &a[i]);
  }
 
  
  //Proc      10101 = 1*2^(4) + 0*2^(3)+ 1*2^(2) +0*2^(1) +1*2^(0)
   Dec=0; 
   for(i=0; i<n; ++i)
   {
     
      Dec= Dec+a[i]* pow(2, (n-1)-i );
     
   }
  
   printf(" \n The Dec = %d", Dec);


  return(0);
  
  
  
  
}
