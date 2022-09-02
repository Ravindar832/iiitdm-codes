#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main()

{

int i, n, ch;

char input[20];

FILE *in;

randomize();

printf(“\n\t\t Stop and Wait Protocol \n”);

printf(“\n 1. Send \n2. Check ACK\n3.EOT\n”);

while(1)

{

printf(“Enter your choice….”);

scanf(“%d”, &ch);

switch(ch)

{

case 1:

in = fopen(“data.txt”, “w”);

Advertisements

REPORT THIS AD

printf(“Enter the Data: “);

scanf(“%s”, input);

n = strlen(input);

for(i=0; i<n+1; i++)

fprintf(in, “%s”, input);

fclose(in);

printf(“——->Data Sent\n”);

break;

getch();

}



Receiver.c
#include<stdio.h>

#include<conio.h>

#include<string.h>

void main()

{

int i, n,;

char output[20];

FILE *out;

clrscr();

out=fopen(“data_parity.txt”, “r”);

fscanf(out, “%s”, output);

n = strlen(output);

for(i=0; i<n; i++)

if(output[i]==’1’)

one++;

if(one%2==0)

{

printf(“Received Data has Even Parity\n”);

printf(“Data Accepted\n”);

}

else

{

printf(“Received Data has Odd Parity\n”);

printf(“Data Rejected\n”);

}

printf(“Received Data: “);

for(i=0;i<n-1; i++)

printf(“%c”, output[i];

fclose(out);

getch();

}