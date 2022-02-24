#include<stdio.h>

//function prototype
int fact(int n);
int fib(int n);
int gcd(int a, int b);
int mul(int a, int b);
int main()
{

  int x, n,i, a,b;
 



  //printf("Enter an int \n");
  //scanf("%d", &n);

 /* Multiline comment
  x=fact(n); //function call
  printf("The factorial of %d is %d", n, x);
  
   x=fib(n); //function call
   printf("The  fib of %d is %d", n, x);

  
    printf("\n The fibonacci seq is : \n");
    for(i=0; i<=n; ++i)
      printf(" %d ", fib(i));
      
   
   
  printf("Enter two int \n");
  scanf("%d %d",&a, &b);
  printf("\n The gcd(%d, %d) is %d  \n",  a,b, gcd(a,b));
  
  
  */
  
  printf("Enter two int \n");
  scanf("%d %d",&a, &b);
  printf("The mul(%d, %d) = %d", a, b, mul(a,b));
  
  
 return(0);
}



int mul(int a, int b)
{
  
  
  if(b==0)
    return(0);
  else
    return(mul(a,b-1)+a);      
  


}


int gcd(int a, int b)
{
   if(b==0)
     return(a);
   else
    return(gcd(b, a%b));
 }



int fib(int n)
{

  if((n==0)||(n==1))
    return(n);
  else
    return(fib(n-1) +fib(n-2));
}


int fact(int n)
{

  if((n==0)||(n==1))
    return(1);
  else
    return(fact(n-1)*n);
}
