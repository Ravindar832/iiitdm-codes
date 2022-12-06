// ravindar
// CS20B1085
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

int count = 0;

char tokenArray[MAX][MAX];

bool isDelimiter(char ch){
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || 
        ch == '"' || ch == '\''
        ){
        return true;
        }    
    return false;
}


bool isOperator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '='){
        return true;
    }    
    return false;
}

bool validIdentifier(char* s){
    if (s[0] == '0' || s[0] == '1' || s[0] == '2' || s[0] == '3' || s[0] == '4' || s[0] == '5' || s[0] == '6' || s[0] == '7' || s[0] == '8' || s[0] == '9' || isDelimiter(s[0]) == true){
        return false;
    }    
    return true;
}

bool isKeyword(char* s){
    if (!strcmp(s, "if") || !strcmp(s, "else") || !strcmp(s, "while") || !strcmp(s, "do") || !strcmp(s, "break") ||
         !strcmp(s, "continue") || !strcmp(s, "int") || !strcmp(s, "double") || !strcmp(s, "float") || !strcmp(s, "return") || !strcmp(s, "char") || !strcmp(s, "case") || !strcmp(s, "char") || !strcmp(s, "sizeof") || !strcmp(s, "long") || !strcmp(s, "short") || !strcmp(s, "typedef") || !strcmp(s, "switch") || !strcmp(s, "unsigned") || 
         !strcmp(s, "void") || !strcmp(s, "static") || !strcmp(s, "struct") || !strcmp(s, "goto")){
        return true;
    }
    return false;
}


bool isInteger(char* s){
    int i, len = strlen(s);
 
    if (len == 0){
        return false;
    }    
    for (i = 0; i < len; i++) {
        if (s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5'
            && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9' || (s[i] == '-' && i > 0)){
            return false;
            }    
    }
    return true;
}

bool isRealNumber(char* s){
    int i, len = strlen(s);
    bool hasDecimal = false;
 
    if (len == 0){
        return (false);
    }    
    for (i = 0; i < len; i++) {
        if (s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5'
            && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9' && s[i] != '.' || (s[i] == '-' && i > 0)){
            return (false);
            }
        if (s[i] == '.'){
            hasDecimal = true;
        }    
    }
    return hasDecimal;
}

char* substring(char* s, int left, int right){
    int i;
    char* substr = (char*)malloc(sizeof(char) * (right - left + 2));
 
    for (i = left; i <= right; i++){
        substr[i - left] = s[i];
    }    
    substr[right - left + 1] = '\0';
    return (substr);
}

void parse(char *s){
    int l = 0, r = 0;
    int len = strlen(s);
    int start = 0;

    while (r <= len && l <= r){
        if (isDelimiter(s[r]) == false)
            r++;

        if (isDelimiter(s[r]) == true && l == r){
            if (isOperator(s[r]) == true){
                tokenArray[count][0] = s[r];
                count++;
            }
            else if (s[r] != ' '){
                tokenArray[count][0] = s[r];
                count++;
                if (s[r] == '\'' || s[r] == '"'){
                    start = 1;
                }
            }
            r++;
            l = r;
        }
        else if (isDelimiter(s[r]) == true && l != r || (r == len && l != r)){
            char *subStr = substring(s, l, r - 1);

            if (isKeyword(subStr) == true){
                for(int i = 0; i < strlen(subStr); i++){
                    tokenArray[count][i] = subStr[i]; 
                }
                count++;
            }

            else if (isInteger(subStr) || isRealNumber(subStr)){
                for(int i = 0; i < strlen(subStr); i++){
                    tokenArray[count][i] = subStr[i]; 
                }
                count++;
            }

            else if (validIdentifier(subStr) == true && isDelimiter(s[r - 1]) == false){
                if (s[r - 1] == '\n'){
                    r++;
                    l = r;
                }
                else if (start == 1){
                    while (s[r] != '"' && s[r] != '\'')
                    {
                        r++;
                    }
                    subStr = substring(s, l, r - 1);
                    for(int i = 0; i < strlen(subStr); i++)
                    {
                        tokenArray[count][i] = subStr[i]; 
                    }
                    count++;

                    l = r;
                    start = 0;
                }
                else{
                    for(int i = 0; i < strlen(subStr); i++)
                    {
                        tokenArray[count][i] = subStr[i]; 
                    }
                    count++;
                }
            }

            else if (validIdentifier(subStr) == false && isDelimiter(s[r - 1]) == false)
            {
                for(int i = 0; i < strlen(subStr); i++)
                {
                    tokenArray[count][i] = subStr[i]; 
                }
                count++;
            }
                
            l = r;
        }
    }
   
}

void removal(FILE *fp, FILE *fo)
{
    char ch, prevch,currch;
    int flag = 0;
    ch = fgetc(fp);
    prevch = '\n';
    currch = ch;
    while (ch != EOF)
    {
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
        {
            if (flag == 0)
            {
                fputc(ch, fo);
                flag = 1;
            }

            ch = fgetc(fp);
        }

        else
        {
            flag = 0;
            if (ch == '/')
            {
                ch = fgetc(fp);
                if (ch == '/')
                {
                    while (ch != '\n')
                    {
                        ch = fgetc(fp);
                    }
                }
                else if (ch == '*')
                {
                    prevch = fgetc(fp);
                    currch = fgetc(fp);
                    int temp = 0;
                    if (currch == '/' || prevch == '*')
                    {
                        temp = 1;
                    }
                    while (temp != 1)
                    {
                        prevch = currch;
                        currch = fgetc(fp);
                        if (currch == '/' && prevch == '*')
                        {
                            temp = 1;
                        }
                    }
                    ch = fgetc(fp);
                }

                else
                {
                    fputc(ch, fo);
                }
                ch = fgetc(fp);
            }

            else if (ch == '#')
            {
                if (prevch == '\n')
                {
                    while (ch != '\n')
                    {
                        ch = fgetc(fp);
                    }
                }
                flag = 1;
            }
            else
            {
                fputc(ch, fo);
                ch = fgetc(fp);
            }
        }
        prevch = currch;
        currch = ch;
    }
}

void token_calculator(){

    char *current_token;
    printf("\nTokens\t\tValue\n");
    for(int i = 0; i < count; i++){
        int sum = 0;
        current_token = tokenArray[i];
        for(int j = i; j < count; j++){
            if(strcmp(current_token, tokenArray[j]) == 0){
                sum++;
                if(sum > 1){
                    for(int a = 0; a < strlen(tokenArray[j]); a++){
                        tokenArray[j][a] = '#';
                    }
                }
            }
        }

        if(tokenArray[i][0] != '#'){
            printf("%s\t\t%d\n", tokenArray[i], sum);
        }
    }
}
int main(int argc, char** argv){
    char ch, character[MAX];

    FILE *fp, *fo;
    fp = fopen("input.c", "r");
    fo = fopen("output.c", "w");

    if(fp == NULL){
        printf("Input file is empty or does not exist.\n");
        exit(0);
    }

    removal(fp, fo);
    fclose(fp);
    fclose(fo);

    FILE *fq=fopen("output.c", "r");

    while(fgets(character, sizeof(character), fq) != NULL){
        parse(character);
    }

    fclose(fq);

    token_calculator();

    return 0;
}
