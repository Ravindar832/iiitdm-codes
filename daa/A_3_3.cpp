#include <iostream>
using namespace std;

class Iterative_Recurssive
{
    int arr[1000];
    int n;

public:
    int Iterative_Binary_search(int arr[], int n, int x)
    {
        int start = 0, end = n, num = 0;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == x)
                return mid;
            else if (arr[mid] < x)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }

    int Recurssive_binary_search(int arr[], int start, int end, int x)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            return Recurssive_binary_search(arr, mid + 1, end, x);
        else
            return Recurssive_binary_search(arr, start, mid - 1, x);
    }

    int Recurssive_ternary_Search(int l, int r, int key, int ar[])
    {
        if (r >= l)
        {

            // Find the mid1 and mid2
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;

            // Check if key is present at any mid
            if (ar[mid1] == key)
            {
                return mid1;
            }
            if (ar[mid2] == key)
            {
                return mid2;
            }

            // Since key is not present at mid,
            // check in which region it is present
            // then repeat the Search operation
            // in that region
            if (key < ar[mid1])
            {

                // The key lies in between l and mid1
                return Recurssive_ternary_Search(l, mid1 - 1, key, ar);
            }
            else if (key > ar[mid2])
            {

                // The key lies in between mid2 and r
                return Recurssive_ternary_Search(mid2 + 1, r, key, ar);
            }
            else
            {

                // The key lies in between mid1 and mid2
                return Recurssive_ternary_Search(mid1 + 1, mid2 - 1, key, ar);
            }
        }

        // Key not found
        return -1;
    }

    int Iterative_ternary_Search(int l, int r, int key, int ar[])

    {
        while (r >= l)
        {

            // Find the mid1 and mid2
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;

            // Check if key is present at any mid
            if (ar[mid1] == key)
            {
                return mid1;
            }
            if (ar[mid2] == key)
            {
                return mid2;
            }

            // Since key is not present at mid,
            // check in which region it is present
            // then repeat the Search operation
            // in that region

            if (key < ar[mid1])
            {

                // The key lies in between l and mid1
                r = mid1 - 1;
            }
            else if (key > ar[mid2])
            {

                // The key lies in between mid2 and r
                l = mid2 + 1;
            }
            else
            {

                // The key lies in between mid1 and mid2
                l = mid1 + 1;
                r = mid2 - 1;
            }
        }

        // Key not found
        return -1;
    }
};

int main()
{
    Iterative_Recurssive IR1;
    int n;
    cout << "Enter the size of array : \n";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cout << "Enter the element to search : \n";
    cin >> x;
    if (IR1.Iterative_Binary_search(arr, n, x) == -1 || IR1.Recurssive_binary_search(arr, 0, n, x) == -1 || IR1.Iterative_ternary_Search(0, n, x, arr) == -1 || IR1.Recurssive_ternary_Search(0, n, x, arr) == -1)
        cout << "---------NOT FOUND---------\n";
    else
    {
        cout << "----------Iterative Binary search-------------\n";
        cout << "Position of " << x << " is " << IR1.Iterative_Binary_search(arr, n, x) + 1 << "\n";
        cout << "----------Recurssive Binary search-------------\n";
        cout << "Position of " << x << " is " << IR1.Recurssive_binary_search(arr, 0, n, x) + 1 << "\n";
        cout << "----------Recurssive ternary search-------------\n";
        cout << "Position of " << x << " is " << IR1.Recurssive_ternary_Search(0, n, x, arr) + 1 << "\n";
        cout << "----------Iterative ternary search-------------\n";
        cout << "Position of " << x << " is " << IR1.Iterative_ternary_Search(0, n, x, arr) + 1 << "\n";
    }
}