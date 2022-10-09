#include <iostream>
using namespace std;

int main() {
    int t;cin>>t;
    while(t--){
        int a,b,x,y;
        cin>>a>>b>>x>>y;
        
        float k,m;
        k = a/x;
        m = b/y;
        
        if(k==m){
            cout<<"both"<<endl;
        }
        else if(k<m){
            cout<<"chef"<<endl;
        }
        else if(k>m){
         cout<<"chefina"<<endl;
        }
        
    }
	return 0;
}