#include <iostream>
#include <cmath>

using namespace std;

int main() {

  long long n;
  cout << "Enter a binary number: ";
  cin >> n;

  int dec = 0, i = 0, rem;
  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

   cout<<dec<<endl;
   int k, f;
   int y = 1;
  
    f = (dec/pow(2,y));
    k = (dec ^ f);
    if(k<dec){
        y++;
    }  
    cout<<y<<endl;

  return 0;
}

// #include <iostream>
// #include <cmath>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         long long n;
//         //   cout << "Enter a binary number: ";
//         cin >> n;

//         int dec = 0, i = 0, rem;
//         while (n != 0)
//         {
//             rem = n % 10;
//             n /= 10;
//             dec += rem * pow(2, i);
//             ++i;
//         }

//         cout << dec << endl;
//         int k, f;
//         int y = 0;
//         while (dec != 0)
//         {
//             f = (dec / pow(2, y));
//             k = (dec ^ f);
//             if (k <= dec)
//             {
//                 y++;
//             }
//             else
//             {
//                 break;
//             }
//             cout << y << endl;
//         }
//         cout << k << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <cmath>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         long long n;
//         //   cout << "Enter a binary number: ";
//         cin >> n;

//         int dec = 0, i = 0, rem;
//         while (n != 0)
//         {
//             rem = n % 10;
//             n /= 10;
//             dec += rem * pow(2, i);
//             ++i;
//         }

//         //   cout<<dec<<endl;
//         int k, f;
//         int y = 0;
//         while (dec != 0)
//         {
//             f = (dec / pow(2, y));
//             k = (dec ^ f);
//             if (k < dec)
//             {
//                 ++y;
               
//             }
//             else
//             {   
//                 y=1;
//                 break;
//             }
//               cout << y << endl;
//         }
//         //    cout<<k<<endl;
//         //    break;
//     }
//     return 0;
// }
