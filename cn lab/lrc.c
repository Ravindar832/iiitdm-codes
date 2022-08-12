
#include<stdio.h>
#include<conio.h>
int binary(int);
void parity(int [],int []);

int arr[8],arr1[8],parityarr[8];
            char chr;
            int go,temp,temp1,i;

void main()
{       char chr1;
            clrscr();
            go=0;

            Sender:
            if(go==0)
            printf("Enter Data : \n");
            printf("\nEnter a character : ");
            scanf("%c %c",&chr,&chr1);


            temp=chr;
            binary(temp);
            printf("\n\nAscii value is : %d\n",temp);
            printf("\nBinary Form : ");
                        for(i=7;i>=0;i--)
                        {
                                    arr1[i]=arr[i];
                                    printf("%d ",arr[i]);
                        }
                        printf("\n");

            temp1=chr1;
            binary(temp1);
            printf("\n\nAscii value is : %d\n",temp1);
            printf("\nBinary Form : ");
                        for(i=7;i>=0;i--)
                        {
                                    printf("%d ",arr[i]);
                        }
            parity(arr,arr1);
            for(i=7;i>=0;i--)
            {
                        arr[i]=0;
                        arr1[i]=0;
            }
            getch();
}

void parity(int arr[],int arr1[])
{
            printf("Receiver Side :\n");
printf("\n\nLRC :\n");
            for(i=7;i>=0;i--)
                        {
                                    printf("%d ",arr[i]);
                        }
                        printf("\n");
            for(i=7;i>=0;i--)
                        {
                                    printf("%d ",arr1[i]);
                        }
            for(i=0;i<8;i++)
            {
                        if(arr[i]==0 && arr1[i]==0 || arr[i]==1 && arr1[i]==1)
                        {
                                 parityarr[i]=0;
                        }
                        else if(arr[i]==1 && arr1[i]==0 || arr[i]==0 && arr1[i]==1)
                        {
                                    parityarr[i]=1;
                        }
            }
            for(i=7;i>=0;i--)
            {
                        printf("%d ",parityarr[i]);
            }

}

int binary(int x)
{
            int rem;
            int ctr=0,i=1;
            do
            {
                        rem=x%2;
                        arr[i]=rem;
                        if(rem==1)
                        {
                                    ctr++;
                        }
                        x=x/2;
                        i++;
            }
            while(x!=0);
            if(ctr%2==0)
            {
                        arr[0]=0;
            }
            else
            {
                        arr[0]=1;
            }
            return(0);
}