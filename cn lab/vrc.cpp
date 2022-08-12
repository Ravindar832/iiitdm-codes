#include<bits/stdc++.h>
using namespace std;

int binary(int);
void parity(int[]);
// int arr[9], arr1[9];
//     int temp,temp1,i;
//     string data;
void main()
{   
    int arr[9], arr1[9];
    int temp,temp1,i;
    string data;
    cout<<"enter data\n";
    cin>>data;

    temp = data;
    binary(temp);

    cout<<"\nBinary Form : ";

                        for(i=0;i<8;i++)
                        {
                                    arr1[i]=arr[i];
                                    cout<<arr[i];
                        }

                        cout"\n";
                        parity(arr);
                        getch();
                        return 0;
}
void parity(int a[])
{
            int count;
            count=0;
            for(i=0;i<8;i++)
            {
                        if(a[i]==1)
                                    count++;
            }
            if(count%2==0)
                        a[8]=0;
            else
                        a[8]=1;
            count=0;
            cout<<"Receiver Side :\n";
            cout"\n\nVRC : \n";
            for(i=0;i<9;i++)
                        {
                                    if(i==8)
                                                cout" | ";
                                    cout<<a[i];
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
