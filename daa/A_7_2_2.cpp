#include <iostream>
#include <math.h>
using namespace std;

int sum(int freq[], int i, int j);

int optCost(int freq[], int i, int j)
{
    if (j < i)
        return 0;
    if (j == i)
        return freq[i];

    int fsum = sum(freq, i, j);

    int min = pow(2, 20);

    for (int r = i; r <= j; ++r)
    {
        int cost = optCost(freq, i, r - 1) +
                   optCost(freq, r + 1, j);
        if (cost < min)
            min = cost;
    }

    // Return minimum value
    return min + fsum;
}

int optimalSearchTree(int keys[],
                      int freq[], int n)
{
    return optCost(freq, 0, n - 1);
}

int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int main()
{
    int n;
    cout << "Enter the size of arrays\n";
    cin >> n;

    int key[n], Frequency[n];
    cout << "Enter the KEY array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> key[i];
    }
    cout << "Enter the FREQUENCY array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> Frequency[i];
    }
    cout << "Cost of Optimal BST is "
         << optimalSearchTree(key, Frequency, n);

    return 0;
}