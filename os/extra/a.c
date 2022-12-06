#include<stdio.h>
#include<unistd.h>
int main()
{
    // if (fork() && fork())
    // {
    //     // fork();
    //     // fork();
    //     printf("parent\n");
    // }else{
    //      fork();
    //      fork();
    //     printf("child\n");
    // }
//     if ((fork() || fork() )&& fork())
//      {
//     //     // fork();
//     //     // fork();
//        printf("parent\n");
//      }else{
//     //      fork();
//     //      fork();
//    printf("child\n");
//}

     if (fork() && fork())
    
    //     // fork();
          fork();
    //     printf("parent\n");

    //      fork();
    //      fork();
        printf("child\n");


    return 0;
    
}