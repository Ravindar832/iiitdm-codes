// #include <iostream>
// #include <cmath>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         std::cin >> n;
//         string arr;
//         std::cin >> arr;

//         int i, N, dec = 0, p = 0;
//         N = arr.size();
//         for (i = N - 1; i >= 0; i--)
//         {
//             if (arr[i] == '1')
//             {
//                 dec += pow(2, p);
//             }
//             p++;
//         }

//         //    cout<<dec<<endl;
//         int g, f;
//         int y = 1;

//         f = (dec / pow(2, y));
//         g = (dec ^ f);
//         if (g < dec)
//         {
//             y++;
//         }
//         cout << y << endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count++;
            }
            else{
                break;
            }
        }
        cout<<count<<endl;
        
    }
    return 0;
}