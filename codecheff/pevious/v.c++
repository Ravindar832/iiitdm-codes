

// CPP program to find the
// longest substring of vowels.
#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
	return (c == 'a' || c == 'e' || c == 'i'
			|| c == 'o' || c == 'u');
			
}

int main()
{
	int t;
    cin >> t;
    while(t--){
        string s;cin>>s;
        int z=s.size();
        int ct=0;
        for(int i=0;i<z-2;i++){
            if(isVowel(s[i]) && isVowel(s[i+1]) && isVowel(s[i+2])){
                ct++;
                break;
            }
                
        }
        if(ct == 0)
            cout<<"Sad"<<endl;
        else
            cout<<"Happy"<<endl;
    
    
    return 0;
}

