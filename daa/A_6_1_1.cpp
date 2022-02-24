#include <iostream>
using namespace std;

int count = 0;

class Coin_change
{
    int arr[1000];
    int n;

public:
    void sort(int arr[], int n)
    {
        int i, j, k, l;
        for (i = 0; i < n - 1; i++)
        {
            k = i;
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[k])
                    k = j;
            }
            l = arr[k];
            arr[k] = arr[i];
            arr[i] = l;
        }
    }
    void minimum_coins_required(int arr[], int n, int v)
    {
        sort(arr, n);
        if (v < arr[0])
        {
            cout << "********INVALID AMOUNT*******\n";
        }
        else
        {
            cout << " ------------Denomination required for that amount is------------- \n";
            for (int i = n - 1; i >= 0; i--)
            {
                while (v >= arr[i])
                {
                    v = v - arr[i];
                    cout << " " << arr[i];
                    count++;
                }
            }
        }
    }
};

int main()
{
    Coin_change C1;
    int n, v;
    int arr[1000];
    cout << "ENTER THE AMOUNT : \n";
    cin >> v;
    cout << "ENTER THE NUMBER OF COINS(DENOMINATION) : \n";
    cin >> n;
    cout << "Enter the elements of the array : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    C1.minimum_coins_required(arr, n, v);
    cout << endl;
    cout << "------Nunmber of coins required are------\n";
    cout << count << endl;
}