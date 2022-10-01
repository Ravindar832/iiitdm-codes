#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int validate_number(char *str) {
   while (*str) {
      if(!isdigit(*str)){ //if the character is not a number, return false
         return 0;
      }
      str++; //point to next character
   }
   return 1;
}
int validate_ip(char *ip) { //check whether the IP is valid or not
   int i, num, dots = 0;
   char *ptr;
   if (ip == NULL)
      return 0;
      ptr = strtok(ip, "."); //cut the string using dor delimiter
      if (ptr == NULL)
         return 0;
   while (ptr) {
      if (!validate_number(ptr)) 
         return 0;
         num = atoi(ptr); //convert substring to number
         if (num >= 0 && num <= 255) {
            ptr = strtok(NULL, "."); //cut the next part of the string
            if (ptr != NULL)
               dots++; //increase the dot count
         } else
            return 0;
    }
    if (dots != 3) //if the number of dots are not 3, return false
       return 0;
      return 1;
}
int class(char *ip){
    int i, num, dots = 0;
   char *ptr;
   if (ip == NULL)
      return 0;
      ptr = strtok(ip, "."); //cut the string using dor delimiter
      if (ptr == NULL)
         return 0;
   int m = 1;
   while (m) {
      if (!validate_number(ptr)) 
         return 0;
         num = atoi(ptr);
         if (num >= 0 && num <= 127){
            printf("class A");
         }
         else if(num > 127 && num <= 191){
            printf("class B");
         }
         else if(num > 192 && num <= 223){
            printf("class c");
         }
         else if(num > 223 && num <= 239){
            printf("class D");
         }
         else if(num > 239 && num <= 250){
            printf("class E");
         }
         else{
            printf("invalid class");
         }
      m = 0;
   }

}
int main()
{
    char str[250];
    printf("enter the ip address \n");
    scanf("%s",str);
    validate_ip(str)? printf("Valid\n"): printf("Not valid\n");
    class(str);
   
    
}