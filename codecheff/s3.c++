#include <iostream>
#include <cmath>
long long arr;
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
      int n;
        std::cin >> n;
        std::cin >> arr;
        int dec = 0, i = 0, rem;
  while (arr!=0) {
    rem = arr % 10;
    arr /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

//    cout<<dec<<endl;s
   int k, f;
   int y = 1;
  
    f = (dec/pow(2,y));
    k = (dec ^ f);
    if(k<dec){
        y++;
    }  
    cout<<y<<endl;
    }
    return 0;
}