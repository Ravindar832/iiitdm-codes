#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int convert_binary(int a, int b, int c, int d);
int *convert_binary1(int a);
int validate_number(char *str)
{
   while (*str)
   {
      if (!isdigit(*str))
      { // if the character is not a number, return false
         return 0;
      }
      str++; // point to next character
   }
   return 1;
}
int validate_ip(char *ip)
{ // check whether the IP is valid or not
   int i, num, dots = 0;
   char *ptr;
   if (ip == NULL)
      return 0;
   ptr = strtok(ip, "."); // cut the string using dor delimiter
   if (ptr == NULL)
      return 0;
   while (ptr)
   {
      if (!validate_number(ptr))
         return 0;
      num = atoi(ptr); // convert substring to number
      if (num >= 0 && num <= 255)
      {
         ptr = strtok(NULL, "."); // cut the next part of the string
         if (ptr != NULL)
            dots++; // increase the dot count
      }
      else
         return 0;
   }
   if (dots != 3) // if the number of dots are not 3, return false
      return 0;
   return 1;
}
int class(char *ip)
{
   int i, num, dots = 0;
   char *ptr;
   if (ip == NULL)
      return 0;
   ptr = strtok(ip, "."); // cut the string using dor delimiter
   if (ptr == NULL)
      return 0;
   int m = 1;
   while (m)
   {
      if (!validate_number(ptr))
         return 0;
      num = atoi(ptr);
      if (num >= 0 && num <= 127)
      {
         printf("class A");
      }
      else if (num > 127 && num <= 191)
      {
         printf("class B");
      }
      else if (num > 192 && num <= 223)
      {
         printf("class c");
      }
      else if (num > 223 && num <= 239)
      {
         printf("class D");
      }
      else if (num > 239 && num <= 250)
      {
         printf("class E");
      }
      else
      {
         printf("invalid class");
      }
      m = 0;
   }
}
int *convert_binary1(int a)
{
   int i, j, k, l;
   int *num = (int *)malloc(sizeof(int) * 8); // allocating memory of 8 integers
   for (i = 0; i <= 7; i++)
   {
      num[7 - i] = a % 2;
      a = a / 2;
   }
   return num;
}

int convert_binary(int a, int b, int c, int d)
{
   int i, j, k, l;
   int num[10];
   for (i = 0; i <= 7; i++)
   {
      num[i] = a % 2;
      a = a / 2;
   }
   // return(num);
   for (i = 7; i >= 0; i--)
   {
      printf("%d", num[i]);
   }
   printf(".");

   for (j = 0; j <= 7; j++)
   {
      num[j] = b % 2;
      b = b / 2;
   }
   for (j = 7; j >= 0; j--)
   {
      printf("%d", num[j]);
   }
   printf(".");

   for (k = 0; k <= 7; k++)
   {
      num[k] = c % 2;
      c = c / 2;
   }
   for (k = 7; k >= 0; k--)
   {
      printf("%d", num[k]);
   }
   printf(".");

   for (l = 0; l <= 7; l++)
   {
      num[l] = d % 2;
      d = d / 2;
   }
   for (l = 7; l >= 0; l--)
   {
      printf("%d", num[l]);
   }
}


main()

{
   char str[250];
   printf("enter the ip address \n");
   scanf("%s", str);
   validate_ip(str) ? printf("Valid\n") : printf("Not valid\n");
   class(str);
   int i, j;       // loop index
   int ip[4];      // array to store ip seperated by "."
   int binary[32]; // store ip in binary
   int *bin;
   char *piece;
   char input[20];

   printf("\nEnter ip address:");
   scanf("%s", input); // read ip as string

   piece = strtok(input, "."); // split . seperated ip , first call to the function strtok will return first piece in the string, subsequent calls to the function with null as first parameter will return subsequent pieces
   i = 0;
   do
   {
      ip[i++] = atoi(piece);     // atoi(string) converts string to integer, store pieced string into integer array
      piece = strtok(NULL, "."); // this is subsequent call
   } while (piece && i < 4);

   for (j = 0; j < 4; j++) // loop through ips e.g 192.168.0.1  first loop will process ip[0] which has 192 stored
   {
      bin = convert_binary1(ip[j]); // convert integer to binary , stored in integer array
      for (i = 0; i < 8; i++)
      {
         binary[j * 8 + i] = bin[i]; // store converted binary into correct position in 32 binary array
      }
   }

   for (i = 0; i < 32; i++)
   {
      if (i > 0 && (i) % 8 == 0)
         printf(".");          // print a "." after printing 8 digits
      printf("%d", binary[i]); // print binary values of given ip saved in this int array
   }
   printf("\n");
}

