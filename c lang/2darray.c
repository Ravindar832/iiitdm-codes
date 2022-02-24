// To understand the realtionship between Arrays and pointers

#include<stdio.h>
void Print_Mat(int m, int n,  int a[][n]);
int main()
{
  int m,n,i,j;
  printf("\n Enter matrix size \n");
  scanf("%d %d", &m, &n);

 //dec of 2D array
 int a[m][n];
 
  printf("\n Enter a matrix of size (%d, %d) \n", m, n);
  for(i=0; i<m; ++i)
    for(j=0; j<n; ++j)
      scanf("%d", &a[i][j]);

  Print_Mat(m, n, a);
 

 return(0);
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
