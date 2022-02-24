#include <iostream>
using namespace std;

/* Ex:- 3, 0, 2, 0, 5   */

class Trap_water
{
    int arr[1000];
    int n;

public:
    int maximum_Water(int arr[], int n)
    {
        int result = 0, i, j, left_side[n], right_side[n];

        left_side[0] = arr[0];
        right_side[n - 1] = arr[n - 1];
        // maximum element on its left

        for (i = 1; i < n; i++)
            left_side[i] = max(left_side[i - 1], arr[i]);

        //maximum element on its right
        for (i = n - 2; i >= 0; i--)
            right_side[i] = max(right_side[i + 1], arr[i]);

        //maximum water
        for (i = 0; i < n; i++)
            result = result + (min(left_side[i], right_side[i]) - arr[i]);

        return result;
    }
};

// Driver code
int main()
{
    Trap_water T1;
    int n, i;
    cout << "Enter the size of array : \n";
    cin >> n;
    int array[n];
    cout << "Enter the array :\n";
    for (i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << "The maximum water stored is :\n";
    cout << T1.maximum_Water(array, n) << "\n";

    return 0;
}