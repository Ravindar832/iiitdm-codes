/*
NAME:-C.Vineeth Babu
ROLL NO:-CS20B1025
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <ctype.h>


int op = 0, specialSymbols = 0, constants = 0, keywords = 0, strings = 0, identifiers = 0;

bool isDelimiter(char ch){
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}' || 
        ch == '"' || ch == '\''
        )
        return (true);
    return (false);
}

bool isOperator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return (true);
    return (false);
}

bool isValidIdentifier(char* str){
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || isDelimiter(str[0]) == true)
        return (false);
    return (true);
}
 
bool isKeyword(char* str){
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}
 
bool isInteger(char* str){
    int i, len = strlen(str);
 
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}
 
bool isRealNumber(char* str){
    int i, len = strlen(str);
    bool hasDecimal = false;
 
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}
 

bool isSpecialCharacter(char ch){
    if(ch == '"' || ch == '\'' || ch == '{' || ch == '}' ||
       ch == '[' || ch == ']' || ch == '(' || ch == ')'  ||
       ch == '#' || ch == ',' || ch == ':' || ch == ';'){
        return true;
    }
    return false;
}

char* subString(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(
                  sizeof(char) * (right - left + 2));
 
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}
 
void parseFile(char* str){
    int left = 0, right = 0;
    int len = strlen(str);
    int state = 0, tempv = 1, stringStart = 0;
    char *token;

    while(right <= len && left <= right){
        if(!isDelimiter(str[right]))
        {
            right++;
        }
        else{
            if(left == right){
                if(isOperator(str[right+1])){
                    if(isOperator(str[right])){
                        right+=2;
                        token = subString(str, left, right - 1);
                        tempv = 0;
                        left = right;
                    }
                    else{
                        token = &str[right];
                        right++;
                        left = right;
                        tempv = 1;
                    }
                }
                else{
                    token = &str[right];
                    right++;
                    left = right;
                    tempv = 1;
                }
            }
            else{
                if(stringStart == 0){
                    token = subString(str, left, right - 1);
                }
                else{
                    while(str[right] != '"' && str[right] != '\''){
                        right++;
                    }
                    token = subString(str, left, right - 1);
                    state = 6;
                }
                left = right;
                tempv = 0; 
            }

        char ch;
        int i = 0;
        int loopVariable = 1;

        while(loopVariable){
            switch(state){
                case 0: {
                    ch = token[i];
                    i++;
                    if(isalpha(ch)){
                        state = 1;
                        break;
                    }
                    else if(isdigit(ch)){
                        state = 2;
                        break;
                    }
                    else if(isOperator(ch)){
                        state = 4;
                        break;
                    }
                    else{
                        state = 5;
                        break;
                    }
                }
                break;

                case 1: {
                    ch = token[i];
                    i++;
                    if(isalpha(ch) || isdigit(ch)){
                        state = 1;
                        break;
                    }
                    else if(isKeyword(token)){
                        printf("'\033[0;34m%s\033[0m' - Keyword,State - %d\n", token, state);
                        keywords++;
                        loopVariable = 0;
                        break;
                    }
                    else if(ch != ' '){
                        if(!tempv){
                            printf("'\033[0;34m%s\033[0m' - Identifier,State - %d\n", token, state);
                        }
                        else{
                            printf("'\033[0;34m%c\033[0m' - Identifier,State - %d\n", token[0], state);
                        }
                        identifiers++;
                        loopVariable = 0;
                        break;
                    }
                    else{
                        loopVariable = 0;
                    }
                }
                break;

                case 2: {
                    ch = token[i];
                    i++;
                    if(isdigit(ch)){
                        state = 2;
                        break;
                    }
                    else if(ch == '.'){
                        state = 3;
                        break;
                    }
                    else if(ch == 'u' || ch == 'U' || ch == 'I' || ch == 'L'){
                            if(!tempv){
                                printf("'\033[0;34m%s\033[0m' - Integer,State - %d\n", token, state);
                            }
                            else{
                                printf("'\033[0;34m%c\033[0m' - Integer,State - %d\n", token[0], state);
                            }
                            constants++;
                            loopVariable = 0;
                            break;
                    }
                    else{
                        if(!tempv){
                            printf("'\033[0;34m%s\033[0m' - Integer,State - %d\n", token, state);
                        }
                        else{
                            printf("'\033[0;34m%c\033[0m' - Integer,State - %d\n", token[0], state);
                        }
                        constants++;
                        loopVariable = 0;
                        break;
                    }
                }
                break;

                case 3: {
                    ch = token[i];
                    i++;
                    if(isdigit(ch)){
                        state = 3;
                        break;
                    }
                    else{
                        printf("'\033[0;34m%s\033[0m' - Decimal Number, State - %d\n", token, state);
                        constants++;
                        loopVariable = 0;
                        break;
                    }
                }

                case 4:{
                    ch = token[i];
                    i++;
                    char temp = token[i];
                    if(isOperator(ch)){
                        printf("'\033[0;34m%s\033[0m' - Operator, State - %d\n", token, state);
                    }
                    else{
                        printf("'\033[0;34m%c\033[0m' - Operator, State - %d\n", token[0], state);
                    }
                    op++;
                    loopVariable = 0;
                    break;
                }
                break;

                case 5:{
                    if(ch == '"' || ch == '\''){
                        state = 6;
                        break;
                    }
                    else if(ch != ' '){
                        printf("'\033[0;34m%c\033[0m' - Special Symbol, State - %d\n", token[0], state);
                        specialSymbols++;
                        loopVariable = 0;
                        break;
                    }
                    else{
                        loopVariable = 0;
                        break;
                    }
                }
                break;
                
                case 6:{
                    if(stringStart){
                        printf("'\033[0;34m%s\033[0m' - String,State - %d\n", token, state);
                        strings++;
                        stringStart = 0;
                        loopVariable = 0;
                        break;
                    }
                    else if(ch == '"' || ch == '\''){
                        printf("'\033[0;34m%c\033[0m' - Special symbol - 5\n", ch);
                        specialSymbols++;
                        stringStart = 1;
                        loopVariable = 0;
                        break;
                    }
                }
            
            }
           }
        }

        state = 0;
    }
	return;
}



void remove_extras(FILE *filein, FILE *fileout){
	char ch, currch, prevch;
	int flag = 0;
	ch = fgetc(filein);
	prevch = '\n';
	currch = ch;
	while(ch != EOF){
	if(ch == ' ' || ch == '\t' || ch == '\0' || ch == '\n'){
		if(flag == 0){
			fputc(ch, fileout);
			flag = 1;
		}
		ch = fgetc(filein);
	}else{
		flag = 0;
        if(ch == '#'){
			if(prevch == '\n'){
				while(ch!='\n'){
					ch = fgetc(filein);
				}
			}
			flag = 1;
		}
		else if(ch == '/'){
			ch = fgetc(filein);
			if(ch == '/'){
				while(ch!='\n'){
					ch = fgetc(filein);
				}
			}else if(ch == '*'){
				prevch = fgetc(filein);
				currch = fgetc(filein);
				int temp = 0;
				if(currch == '/' && prevch == '*'){
					temp = 1;
				}
				while(temp != 1){
					prevch = currch;
					currch = fgetc(filein);
				if(currch == '/' && prevch == '*'){
					temp = 1;
				}
				}
				ch = fgetc(filein);
			}else{
				fputc(ch, fileout);
			}
			ch = fgetc(filein);
		}
        else{
			fputc(ch, fileout);
			ch = fgetc(filein);
		}
	}
		prevch = currch;
		currch = ch;
	}
}

int main(int argc, char** argv){
	if(argc != 2){
		printf("Enter the file name as an argument\n");
		exit(1);
	}
	FILE *filein, *fileout;
	filein = fopen(argv[1], "r");
	fileout = fopen("output.c", "w");
    // removing # and extra spaces
	remove_extras(filein, fileout);
	fclose(filein);
	fclose(fileout);
	FILE *fp = fopen("output.c", "r");
	char characters[128];
    printf("State 1: Identifiers and Keywords\n");
    printf("State 2: Integers\n");
    printf("State 3: Decimal Values\n");
    printf("State 4: Operators\n");
    printf("State 5: Special Symbols\n");
    printf("State 6: Strings\n");
    printf("------------------------------------------------------------------\n");
    while(fgets(characters, sizeof(characters), fp) != NULL) {
        parseFile(characters);
    }
    printf("------------------------------------------------------------------\n");
    printf("Identifiers: %d\n", identifiers);
    printf("Keywords: %d\n", keywords);
    printf("Constants: %d\n", constants);
    printf("Operators: %d\n", op);
    printf("Special Chars: %d\n", specialSymbols);
    printf("Strings: %d\n", strings);
    printf("------------------------------------------------------------------\n");
	return 0;
}



/*

*/
