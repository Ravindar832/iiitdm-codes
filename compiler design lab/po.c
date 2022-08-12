#include <stdio.h> 
#include <stdlib.h> 
 
int main(int argc, char const *argv[]) 
{ 
    FILE* inp; 
    inp = fopen("filename","r");		//filename of your data file 
    char arr[100][50];			//max word length 50 
    int i = 0; 
    while(1){ 
        char r = (char)fgetc(inp); 
        int k = 0; 
        while(r!=',' && !feof(inp)){	//read till , or EOF 
            arr[i][k++] = r;			//store in array 
            r = (char)fgetc(inp); 
        } 
        arr[i][k]=0;		//make last character of string null  
        if(feof(inp)){		//check again for EOF 
            break; 
        } 
        i++; 
    } 
    int j; 
    for(j = 0;j<=i;j++){ 
        printf("%s\n",arr[j] );	//print array 
    } 
    return 0; 
}