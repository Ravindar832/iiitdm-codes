#include <iostream>
using namespace std;

class Sub_arrays
{
    int arr[1000];
    int n;

public:
    long long int Sum_of_all_sub_arrays(int arr[], int n)
    {
        int i, j;
        long long int result_1 = 0;
        for (i = 0; i < n; i++)
        {
            /* Every element occurs (n-i)*(i+1) times and multiplying it to element and summing up gives the result */
            result_1 = result_1 + (arr[i] * (n - i) * (i + 1));
        }
        return result_1;
    }
    void print_all_subarrays(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {

            for (int j = i; j <= n; j++)
            {
                for (int k = i; k < j; k++)
                {
                    cout << arr[k]
                         << " ";
                }
                cout << "\n";
            }
        }
    }
};

int main()
{
    Sub_arrays s1;
    int n, i;
    cout << "Enter the size of array : \n";
    cin >> n;
    int array[n];
    cout << "Enter the array :\n";
    for (i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << "All sub arrays are :\n";
    s1.print_all_subarrays(array, n);
    cout << "The sum of all sub arrays are :\n";
    cout << s1.Sum_of_all_sub_arrays(array, n);
}