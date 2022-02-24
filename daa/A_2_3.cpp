#include <iostream>
using namespace std;

class GTA
{
    int arr[1000];
    int n;
    int sum;

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
    int gettriplet(int arr[], int n, int sum)
    {
        int j, k, count = 0;
        sort(arr, n);
        for (int i = 0; i < n - 2; i++)
        {
            for (j = i + 1, k = n - 1; j < k;)
            {
                // if the sum of any three elemnts of sub array matches with sum then count will be increased
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    count++;
                    j++;
                    k--;
                }
                else if (arr[i] + arr[j] + arr[k] < sum)
                    // if less than sum j will be incremented
                    j++;
                else
                    // if more than sum k will be decremented
                    k--;
            }
        }
        return count;
    }
};
int main()
{
    GTA g1;
    int n, l, a;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (l = 0; l < n; l++)
        cin >> arr[l];
    int sum;
    cout << "Enter the sum\n";
    cin >> sum;
    a = g1.gettriplet(arr, n, sum);
    cout << "Number of such triplets are :\n";
    cout << a << endl;

    return 0;
}