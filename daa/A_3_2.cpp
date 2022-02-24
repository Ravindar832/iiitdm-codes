#include <iostream>
using namespace std;

class Count_negative
{
    int arr[100];
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
    int get_count_two_way(int arr[], int n)
    {
        sort(arr, n);
        int start = 0, end = n - 1, num = n;
        // this while loop updates 'num' by number of elements less zero
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] >= 0)
            {
                num = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        //finally returning negative integers
        return (num);
    }
    int Three_way(int l, int r, int arr[])
    {
        sort(arr, n);
        int num = r + 1;
        while (r >= l)
        {

            // Find the mid1 and mid2
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;

            // Check if positive number is present at any mid
            if (arr[mid1] >= 0)
            {
                num = mid1; // this num gives (size of array - positive numbers)
                r = mid1 - 1;
            }
            else if (arr[mid2] >= 0)
            {
                num = mid2; // this num gives (size of array - positive numbers)
                r = mid2 - 1;
            }
            else
            {

                // if negative lies b/w mid1 and mid2
                l = mid1 + 1;
            }
        }
        return num; // returning negative numbers
    }
};

int main()
{
    Count_negative C1;
    int n;
    cout << "Enter the size of the array : \n";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Number of Negative intergers(using 2-way) in this array is/are \n";
    cout << C1.get_count_two_way(arr, n) << "\n";
    cout << "Number of Negative intergers(using 3-way) in this array is/are \n";
    cout << C1.Three_way(0, n - 1, arr) << "\n";
}