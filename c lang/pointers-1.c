//Pointers, passing by values Vs passing by address

#include<stdio.h>
void modify(int x, float y, char z);
void MODIFY(int *px, float *py, char *pz);
int main()
{
  int x;
  float y;
  char z;
  
  printf("\n Enter int, float, char \n");
  scanf("%d %c %f", &x, &z, &y);
  
  printf("%d  %c %f", x, z,y);

  //modify(x,y,z);
  
  
  
  //printf("\n After function call: %d  %c %f \n", x, z,y);

  MODIFY(&x, &y,&z);
  
printf("\n After function call  MODIFY: %d  %c %f \n", x, z,y);

  return(0);
}

void MODIFY(int *px, float *py, char *pz)
{
   
   
   *px=100;
   *py=200.67;
   *pz='Q';
  printf("\n After change: %d  %c %f \n ", *px, *pz,*py);

}


void modify(int x, float y, char z)
{
   printf(" \n Before change: %d  %c %f  \n", x, z,y);
   
   x=100;
   y=200.67;
   z='Q';
  printf("\n After change: %d  %c %f \n ", x, z,y);

}

