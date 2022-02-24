#include <iostream>
using namespace std;

// class of sorts
class SORTS
{
    int arr[1000];
    int n;

public:
    void Insertion_sort(int arr[], int p, int q)
    {
        for (int i = p; i < q; i++)
        {
            int tempVal = arr[i + 1];
            int j = i + 1;
            while (j > p && arr[j - 1] > tempVal)
            {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = tempVal;
        }
    }

    void merge(int arr[], int p, int q, int r)
    {

        // Create L ← A[p..q] and M ← A[q+1..r]
        int n1 = q - p + 1;
        int n2 = r - q;

        int L[n1], M[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[p + i];
        for (int j = 0; j < n2; j++)
            M[j] = arr[q + 1 + j];

        // Maintain current index of sub-arrays and main array
        int i, j, k;
        i = 0;
        j = 0;
        k = p;

        // Until we reach either end of either L or M, pick larger among
        // elements L and M and place them in the correct position at A[p..r]
        while (i < n1 && j < n2)
        {
            if (L[i] <= M[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = M[j];
                j++;
            }
            k++;
        }

        // When we run out of elements in either L or M,
        // pick up the remaining elements and put in A[p..r]
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = M[j];
            j++;
            k++;
        }
    }

    void hybrid_sort(int arr[], int l, int r)
    {
        if (r - l + 1 <= 20 && r - l + 1 > 0)
        {
            Insertion_sort(arr, l, r);
        }
        else if (r - l + 1 > 20)
        {
            if (l < r)
            {
                // m is the point where the array is divided into two subarrays
                int m = l + (r - l) / 2;
                hybrid_sort(arr, l, m);
                hybrid_sort(arr, m + 1, r);

                // Merge the sorted subarrays
                merge(arr, l, m, r);
            }
        }
    }
};
int main()
{
    SORTS s1;
    int n, i;
    cout << "Enter the size of array : ";
    cin >> n;
    int array[n];
    cout << "Enter the array : \n";
    for (i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    s1.hybrid_sort(array, 0, n - 1);
    cout << "Sorted array is :";
    for (i = 0; i < n; i++)
    {
        cout << " " << array[i];
    }
    cout << "\n";
    cout << "\n";

    return 0;
}