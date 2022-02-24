#include <iostream>
using namespace std;

// class of sorts
class SORTS
{
    int arr[1000];
    int n;

public:
    void swap(int *xp, int *yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

    void Selection_sort(int arr[], int n)
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
            swap(&arr[k], &arr[i]);
        }
    }

    void Bubble_sort(int arr[], int n)
    {
        int i, j;
        for (i = 0; i < n - 1; i++)
        {
            int flag = 0;
            for (j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(&arr[j], &arr[j + 1]);
                    flag = 1;
                }
                if (flag == 0)
                    break;
            }
        }
    }

    void Insertion_sort(int arr[], int n)
    {
        int i, key, j;
        for (i = 1; i < n; i++)
        {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
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

    void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            // m is the point where the array is divided into two subarrays
            int m = l + (r - l) / 2;

            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            // Merge the sorted subarrays
            merge(arr, l, m, r);
        }
    }
    void heapify(int arr[], int n, int i)
    {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);

            // Recursively heapify the sub-tree
            heapify(arr, n, largest);
        }
    }
    void heapSort(int arr[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--)
        {
            swap(&arr[0], &arr[i]);

            //max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }
};
int main()
{
    SORTS s1;
    int n, i, choice;
    cout << "Enter the size of array : ";
    cin >> n;
    int array[n];
    cout << "Enter the array : \n";
    for (i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    while (1)
    {
        cout << "1. BUBBLE SORT\n2. SELECTION SORT\n3. INSERTION SORT\n4. MERGE SORT\n5. HEAP SORT\n6. EXIT\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s1.Bubble_sort(array, n);
            cout << "ARRAY AFTER BUBBLE SORT IS : ";
            for (i = 0; i < n; i++)
            {
                cout << " " << array[i];
            }
            cout << "\n";
            break;
        case 2:
            s1.Selection_sort(array, n);
            cout << "ARRAY AFTER SELECTION SORT IS : ";
            for (i = 0; i < n; i++)
            {
                cout << " " << array[i];
            }
            cout << "\n";
            break;
        case 3:
            s1.Insertion_sort(array, n);
            cout << "ARRAY AFTER INSERTION SORT IS : ";
            for (i = 0; i < n; i++)
            {
                cout << " " << array[i];
            }
            cout << "\n";
            break;
        case 4:
            s1.mergeSort(array, 0, n - 1);
            cout << "ARRAY AFTER MERGE SORT IS : ";
            for (i = 0; i < n; i++)
            {
                cout << " " << array[i];
            }
            cout << "\n";
            break;
        case 5:
            s1.heapSort(array, n);
            cout << "ARRAY AFTER HEAP SORT IS : ";
            for (i = 0; i < n; i++)
            {
                cout << " " << array[i];
            }
            cout << "\n";
            break;
        default:
            exit(1);
        }
    }

    return 0;
}