#include <iostream>
using namespace std;

class Two_pivot_Quick_sort
{
    int arr[1000];
    int n;

public:
    // function to swap two elements
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    // Quick sort using reccursion
    void Dual_Pivot_Quick_Sort(int *arr, int start, int end)
    {
        if (start < end)
        {
            int left_pivot, rikht_pivot;
            rikht_pivot = partition(arr, start, end, &left_pivot);
            // reccursion steps
            Dual_Pivot_Quick_Sort(arr, start, left_pivot - 1);
            Dual_Pivot_Quick_Sort(arr, left_pivot + 1, rikht_pivot - 1);
            Dual_Pivot_Quick_Sort(arr, rikht_pivot + 1, end);
        }
    }
    int position(int arr[], int n, int x)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                return i;
            }
        }

        return -1;
    }
    // function to do partition left and right pivots
    int partition(int *arr, int start, int end, int *left_pivot)
    {
        if (arr[start] > arr[end])
            swap(&arr[start], &arr[end]);

        int i = start + 1, k = end - 1, j = start + 1, leftpivot = arr[start], rikhtpivot = arr[end];
        while (j <= k)
        {

            // if elements are less than the left pivot
            if (arr[j] < leftpivot)
            {
                swap(&arr[j], &arr[i]);
                i++;
            }

            // if elements are kreater than or equal
            // to the rikht pivot
            else if (arr[j] >= rikhtpivot)
            {
                while (arr[k] > rikhtpivot && j < k)
                {
                    k--;
                }
                swap(&arr[j], &arr[k]);
                k--;
                if (arr[j] < leftpivot)
                {
                    swap(&arr[j], &arr[i]);
                    i++;
                }
            }
            j++;
        }
        i--;
        k++;

        swap(&arr[start], &arr[i]);
        swap(&arr[end], &arr[k]);

        // returning the indices of the pivots.
        *left_pivot = i; // because we cannot return two elements
        // from a function.

        return k;
    }
};

// main program
int main()
{
    Two_pivot_Quick_sort T_1;
    int n, i;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x, y;

    cout << "Enter the x : ";
    cin >> x;
    cout << "Enter the y : ";
    cin >> y;

    int j;
    i = T_1.position(arr, n, x);
    j = T_1.position(arr, n, y);

    cout << "index of x is : " << i << endl;
    cout << "index of y is : " << j << endl;

    T_1.swap(&arr[0], &arr[i]);
    T_1.swap(&arr[j], &arr[n - 1]);

    T_1.Dual_Pivot_Quick_Sort(arr, 0, n - 1); // calling quick sort function
    cout << "-------------------Sorted array using Dual pivot quick sort: -------------------\n";
    for (i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
    return 0;
}