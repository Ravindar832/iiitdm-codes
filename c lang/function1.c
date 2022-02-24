// Factorial

#include<stdio.h>
#include<math.h>
int factorial(int n);
float Exp1(int x);

int main()
{
  int n;
  float y;
  printf("\n Enter val of n \n");
  scanf("%d", &n);

  //function call
  y=Exp1(n);
  
  printf("\n e power %d is %1.10f \n", n, y);



  return(0);
}

float Exp1(int x)
{
  //e^x = x^0/0! +....x^i/i!+....
  int i;
  float sum=0.0, psum=0.0;
  
  for(i=0; i<=30; ++i)
  {
    psum=sum;
    sum=sum+ (float)(pow(x,i))/factorial(i);
    if((sum-psum)<0.00000000001)
     break;
  }
  
  printf("\n i=%d\n", i);
  return(sum);

}


//function definition
int factorial(int n)  //n!- 1*2*...(n-1)
{
 
 int f=1, i;
  if((n==0)||(n==1))
   return(1);
  else
  {
   for(i=2; i<=n; ++i)
     f=f*i; 
   return(f);  
     
  } 



  
}
