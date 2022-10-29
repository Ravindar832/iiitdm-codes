#include <stdio.h>

int main(void) {
    int n;
        int r1,r2,r3,r4;
        int i;
    printf("enter the number of inputs");
    scanf("%d",&n);
    for( i=0;i<n;i++){
        printf("enter the 0 and 1 ");
        scanf("%d %d %d %d",&r1,&r2,&r3,&r4);

    if((r1==0) && (r2==0) && (r3==0) && (r4==0) ){
        printf("in\n");
    }
    
    else{
        printf("out\n");
    }
    }

    
    
    
    // your code goes here
	return 0;
}
