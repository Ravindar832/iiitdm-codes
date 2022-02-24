// To understand the matrix add and mul

#include<stdio.h>

//function prototypes
void Print_Mat(int m, int n,  int a[][n]);
void Add_Mat(int m, int n,  int a[][n], int b[][n]);
void Mul_Mat(int m, int n, int p,   int a[][n], int b[][p]);

int main()
{
  int m,n,i,j,p;
  printf("\n Enter matrix size \n");
  scanf("%d %d %d", &m, &n, &p);

 //dec of 2D arrays
 int a[m][n];
 int b[n][p];
 
 //read matrix a
  printf("\n Enter a matrix of size (%d, %d) \n", m, n);
  for(i=0; i<m; ++i)
    for(j=0; j<n; ++j)
      scanf("%d", &a[i][j]);
      
  //read matrix b    
  printf("\n Enter a matrix of size (%d, %d) \n", n, p);
  for(i=0; i<n; ++i)
    for(j=0; j<p; ++j)
      scanf("%d", &b[i][j]);    
      
      
  //call to add    
// Add_Mat( m, n, a, b);
  //Print_Mat(m, n, a);
 
 //call to mul
 Mul_Mat( m, n,p, a, b); //size of a is mxn, size of b is nxp
 
 
 
 return(0);
} //main function ends



void Mul_Mat(int m, int n, int p,   int a[][n], int b[][p])
{
  int count=0;
  int i,j,sum,k;
  int c[m][p];
  for(i=0; i<m; ++i)
    for(j=0; j<p; ++j) // size of B is nxp
    {
      sum=0;
      for(k=0; k<n; ++k)
      {
        sum=sum+a[i][k]*b[k][j]; //mul of two int
        count=count+1;
      } 
      c[i][j]=sum;  
    }

  printf("\n The number of integer mul is %d \n", count);

 Print_Mat(m, p, c);

}



void Add_Mat(int m, int n,  int a[][n], int b[][n])
{
   int i,j;
   int c[m][n];
    for(i=0; i<m; ++i)
      for(j=0; j<n; ++j)
           c[i][j]=a[i][j]+b[i][j];
   
   Print_Mat(m, n, c);

}




void Print_Mat(int m, int n,  int a[][n])
{
  int i,j;
 printf("Matrix : \n");
  for(i=0; i<m; ++i)
  {  
    for(j=0; j<n; ++j)
      printf(" %d ", a[i][j]); // n is is required in a[][n], because, a[i][j] will be understood by compiler using the formula: a[i][j]=*(a+(n*i)+j) 

    printf("\n");
  }


}
