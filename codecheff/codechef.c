//the cheaper cab

#include <stdio.h>

int main(void) {
    int n;
        int x,y;
        int i;
    printf("enter the number of inputs");
    scanf("%d",&n);
    for( i=0;i<n;i++){
        printf("enter the cab charge of x and y ");
        scanf("%d %d",&x,&y);
        if(x<y){
        printf("first\n");
    }
    else if(x==y){
        printf("any\n");
    }
    else{
        printf("second\n");
    }
    }
    
    // your code goes here
	return 0;
}
