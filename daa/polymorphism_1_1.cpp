#include <bits/stdc++.h>
using namespace std;

vector<int> findLargest(int beg, int end,
                        vector<int> arr, int n)
{

    // Base Condition
    if (beg == end)
    {
        vector<int> compared(n, 0);
        compared[0] = 1;
        compared[1] = arr[beg];
        return compared;
    }
    vector<int> compared1 = findLargest(beg, (beg + end) / 2,arr, n);
    vector<int> compared2 = findLargest((beg + end) / 2 + 1,end, arr, n);

    if (compared1[1] > compared2[1])
    {
        int k = compared1[0] + 1;
        compared1[0] = k;
        compared1[k] = compared2[1];
    }
    else
    {
        int k = compared2[0] + 1;
        compared2[0] = k;

        compared2[k] = compared1[1];
        return compared2;
    }
}

void findSecondLargest(int end, vector<int> arr)
{  
    vector<int> compared1 = findLargest(0, end - 1, arr, end);
    vector<int> compared2 = findLargest(2, compared1[0] + 2,compared1,compared1[0]);
    cout << compared2[1];
}

// Driver code
int main()
{
    int N;
    cin >> N;

    vector<int> arr;
    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        arr.push_back(input);
    }
    cout << "Second largest element in the array is: " << endl;
    findSecondLargest(N, arr);
    cout << endl;

    return 0;
}