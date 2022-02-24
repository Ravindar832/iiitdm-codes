#include <iostream>
using namespace std;

class Insertion_location
{
    int array[1000];
    int n;

public:
    // iterative implementation
    int binarySearch(int array[], int item, int low, int high)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (item == array[mid])
                return mid;
            else if (item > array[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

    // Function to sort an array a[] of size 'n'
    void insertionSort(int array[], int n)
    {
        int i, loc, j, k, selected;

        for (i = 1; i < n; ++i)
        {
            j = i - 1;
            selected = array[i];

            // find location where selected should be inseretd
            loc = binarySearch(array, selected, 0, j);

            // Move all elements after location to create space
            while (j >= loc)
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = selected;
            for (j = 0; j < n; j++)
            {
                cout << " " << array[j];
            }
            cout << "\n";
        }
    }
};

// Driver Code
int main()
{
    Insertion_location I_1;
    int n, i;
    cin >> n;
    int array[n];
    for (i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    I_1.insertionSort(array, n);

    cout << "Final Sorted array is: \n";
    for (i = 0; i < n; i++)
        cout << " " << array[i];

    cout << "\n";

    return 0;
}