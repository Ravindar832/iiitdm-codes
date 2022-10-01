#include<iostream>
using namespace std;
void sort(int a[] ,int n)
{
    int i,j,temp;
    for( i=0;i<n;i++){
        for(j=i+1;j<n;j++){
          if(a[j]<a[i]){

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
          }


        }
    }

}


int main()
{
    int n;
    cout <<" enter the array size "<< endl;
    cin>>n;
    int a[n];
    int i;
    for( i=0; i<n;i++){
        cout<<"enter the array elements"<<endl;
        cin>>a[i];
    }
    sort(a,n);
   cout <<" Sorted array is:" ;
   for (i = 0; i < n; i++)
   cout<< a[i] <<" ";
    
    /* code */
    return 0;
}
