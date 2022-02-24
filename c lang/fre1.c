#include<stdio.h>


int main()
{
  int n,acount=0, bcount=0;
  int john; 
  char var;
  printf("\n Enter no of char to be read");
  scanf("%d", &n);
 
  
  scanf("%c", &var);
 // getchar();
  printf("%c", var);
  printf("Enter %d char", n);
  
 
 
  for(john=0; john<n; ++john)
   {
    scanf("%c", &var);
    
    switch(var)
    {
      case 'a' : acount++;
                 break;
                 
      case 'b'  : bcount++;
                  break;    
                  
                         
    
      default  :   printf(" not a or b");
    
    }
    
    
       
    //printf(" %c ", var);
   }
   
  
  printf("\n acount =  %d; bcount= %d", acount, bcount);



  return(0);
}

/



