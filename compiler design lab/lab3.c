//Given a C program text file as input, write a C program and separate all Words and put all of them in an array.

#include<stdio.h>
#include <string.h> 
void main() 
{ 
	FILE *pfile; 
	char ch, array[50][50]; 
	int count=0, i=0, j=0;  
	pfile=fopen("file1.c","r"); 
	do 
	{ 
        ch=fgetc(pfile);
		if(count == 0 && (ch == ' ' || ch == '\n')) 
		{ 
			array[i][j]='\0'; 
			j=0;
            i++; 
			count = 1; 
		} 
        if(ch != ' ' || ch != '\n') 
		{ 
			array[i][j] = ch; 
            j++; 
			count = 0; 
		} 
		 
	}while (ch != EOF);
	array[i][j] = '\0';
    j = 0;
    i++;  

	for(int k=0;k<i;k++) 
	{ 
        int l = 0;
        while (array[k][l] != '\0')
        {
            printf("%c", array[k][l]);
            l++;
        }
        printf("\n");
				          
	} 
	
} 