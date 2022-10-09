#include <iostream>
using namespace std;

int main() {
    int t;cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        
        int y;
        y = (n*x);
        
        if (y%4 != 0){
            
            y = y/4;
            y++;
	       cout<<y<<endl;

        }
        else if(y%4 == 0){
            int k;
            k = y/4;
            cout<<k<<endl; 
        }
        
    }
	return 0;
}
