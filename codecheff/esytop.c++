

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
       

        int n;
        cin >> n;
        string s;
        cin >> s;

        int consonant = 0;
        bool c = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != 'a' and s[i] != 'e' and s[i] != 'i' and s[i] != 'o' and s[i] != 'u')
                consonant++;
            else
                consonant = 0;

            if (consonant >= 4)
            {
                c = false;
                break;
            }
        }
        if (c)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

    return 0;
}
