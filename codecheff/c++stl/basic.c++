#include <iostream>
#include <bits/stdc++.h>

using namespace std;
template <class t>

t mult(t a, t b)
{
    t res = a * b;
    return res;
}
template <class t>
t Sum(t a, t b)
{
    t s = a + b;
    return s;
}
template <class t>
t Sub(t a, t b)
{
    t r = a - b;
    return r;
}
template <class t>
t Div(t a, t b)
{
    t d = a / b;
    return d;
}
int main()
{
    int a, b, res;
    cout << "eter the sides a and b " << endl;
    cin >> a >> b;

    cout << "mult = " << mult(a, b)<<endl;
    cout << "sum = " << Sum(a, b)<<endl;
    cout << "sub = " << Sub(a, b)<<endl;
    cout << "div = " << Div(a, b)<<endl;
    return 0;
}
