//cs20b1085 gugulothu ravindar


#include<stdio.h>                   
#include<unistd.h>
#include<string.h>
#include<stdlib.h>                            
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int fd1[2],fd2[2];
    pid_t pid;              

   int returnstatus1 = pipe(fd1);
   int returnstatus2 = pipe(fd2);

   char last[80],reverse[80];
    
    pipe(fd1);
    pipe(fd2);

    if(returnstatus1 == -1)
    {
        printf("Unable to create pipe 1!\n");
        return 1;
    }
    
    if(returnstatus2 == -1)
    {
        printf("Unable to create pipe 2!\n");
        return 1;
    }
    
    if((pid = fork()) < 0)
        {
                printf("error");
                exit(1);
        }
    if(pid > 0)
        {
            close(fd1[0]);//closing read end in pipe 1
             close(fd2[1]);//closing write end in pipe 2
        
             printf("\nEnter the message you want to send to the Child Process: ");
            scanf("%s", last);
            write(fd1[1], last, sizeof(last));
        
              read(fd2[0], reverse, sizeof(reverse));
            printf("\nThe Message received from the Child Process is: %s\n", reverse);
            
                 
            
        }
        else
        {
            close(fd1[1]);//closing write end in pipe 1
        close(fd2[0]);//closing read end in pipe 2
        
        read(fd1[0], reverse, sizeof(reverse));
        printf("\nThe Message received from the Parent Process is: %s\n", reverse);
        
        //string reverse function
        int len = strlen(reverse);
        int begin, end = len - 1;
        for (begin = 0; begin < len; begin++)
        {
            last[begin] = reverse[end];
            end--;
        }
        write(fd2[1], last, sizeof(last));
                
        }
        return 0;
    
 }


