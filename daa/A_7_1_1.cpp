#include <bits/stdc++.h>
using namespace std;

int MinCoins(vector<int> const &denominations, int value)
{

    vector<int> dp(value + 1, value + 1);

    //Setting the first element to 0
    dp[0] = 0;

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 0; j < denominations.size(); j++)
        {
            if (denominations[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - denominations[j]] + 1);
            }
        }
    }

    return dp[value] == (value + 1) ? -1 : dp[value];
}

int main()
{
    int amount, input;
    cout << "Enter the amount:";
    cin >> amount;
    int n;
    cout << "Enter the Number of denominations:";
    cin >> n;
    vector<int> denominations;
    cout << "Enter the denominations:";
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        denominations.push_back(input);
    }
    int minimum_coins = MinCoins(denominations, amount);

    if (minimum_coins != -1)
    {
        cout << "Minimum coins required is/are : " << endl;
        cout << minimum_coins << endl;
    }
    else
        cout << "No Combinations are possible" << endl;

    return 0;
}