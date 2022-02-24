//Objective: To understand reading char and its ASCII

// Read char and print its ASCII
#include<stdio.h>
#include<ctype.h>
int main()
{

  char x;
  int y;
  
  printf("Enter a char \n");
  scanf("%c", &x);
  y=x;
   
 printf(" The ASCII of %c is %d \n", x, y );


  return(0);
}
