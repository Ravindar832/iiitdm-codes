#include<stdio.h>
#include<conio.h>
#include<string.h>

void sender()
{   
    char sum[20],complement[20];
    int i,length;
    char a[8]; char b[8];
    // int n;
    for (int i = 0; i < 2; i++)
    {
    printf("enter the data block\n");
     for (int j = 0; j < 2; j++)
     {
        printf("",b[j]);/* code */
        scanf(" %s",&b[j]);  
         scanf("%s",&a[i]);
     }
    }

    if(strlen(a)==strlen(b)){
    length = strlen(a);
    char carry='0';
        
for(i=length-1;i>=0;i--)
        {
if(a[i]=='0' && b[i]=='0' && carry=='0')
            {
                sum[i]='0';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='0' && carry=='1')
            {

 
                sum[i]='1';
                carry='0';
 
            }
            else if(a[i]=='0' && b[i]=='1' && carry=='0')
            {
                sum[i]='1';
                carry='0';
 
            }
            else if(a[i]=='0' && b[i]=='1' && carry=='1')
            {
                sum[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='0')
            {
                sum[i]='1';
                carry='0';
 
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='1')
            {
                sum[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='1' && carry=='0')
            {
                sum[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='1' && carry=='1')
            {
                sum[i]='1';
                carry='1';
 
            }
            else
                break;
        }
        
printf("\nSum=%c%s",carry,sum);
for(i=0;i<length;i++)
        {
            if(sum[i]=='0')
                complement[i]='1';
            else
                complement[i]='0';
        }
        
        if(carry=='1')
            carry='0';
        else
            carry='1';
        
printf("\nChecksum=%c%s",carry,complement);
}
    
      

}
void reciever()
{
   char sum[20],complement[20];
    int i,length;
    char a[8]; char b[8];
    // int n;
    for (int i = 0; i < 3; i++)
    {
    printf("enter the data block\n");
     for (int j = 0; j < 2; j++)
     {
        printf("",b[j]);/* code */
        scanf(" %s",&b[j]);  
         scanf("%s",&a[i]);
     }
    }

    if(strlen(a)==strlen(b)){
    length = strlen(a);
    char carry='0';
        
for(i=length-1;i>=0;i--)
        {
if(a[i]=='0' && b[i]=='0' && carry=='0')
            {
                sum[i]='0';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='0' && carry=='1')
            {

 
                sum[i]='1';
                carry='0';
 
            }
            else if(a[i]=='0' && b[i]=='1' && carry=='0')
            {
                sum[i]='1';
                carry='0';
 
            }
            else if(a[i]=='0' && b[i]=='1' && carry=='1')
            {
                sum[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='0')
            {
                sum[i]='1';
                carry='0';
 
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='1')
            {
                sum[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='1' && carry=='0')
            {
                sum[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='1' && carry=='1')
            {
                sum[i]='1';
                carry='1';
 
            }
            else
                break;
        }
        
printf("\nSum=%c%s",carry,sum);
for(i=0;i<length;i++)
        {
            if(sum[i]=='0')
                complement[i]='1';
            else
                complement[i]='0';
        }
        
        if(carry=='1')
            carry='0';
        else
            carry='1';
        
printf("\nChecksum=%c%s",carry,complement);
}
}

int main()
{
    int n;
    printf("enter 0 to check senders data\n");
    printf("enter 1 to check recievrs data\n");

    printf("enter the value of n\n");
    scanf("%d",&n);

    if (n==0)
    {
        printf("print senders data\n");
        sender(n);
        // return sender;/* code */
    }
    else
    {
        printf("print reciever data", reciever);
        reciever(n);
    }
    
    return 0;
}