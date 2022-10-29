#include <iostream>
using namespace std;
// int increaseDecreaseValue(int array[],
//                           int x, int n)
// {
//     int TotalValue = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (array[i] < x)
//         {

//             for (int j = i + 1; j < n; j++)
//             {
//                 array[j] += 1;
//             }
//         }
//         else
//         {

//             TotalValue += 1;
//             for (int j = i + 1; j < n; j++)
//             {
//                 if (array[j] == 0)
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     array[j] -= 1;
//                 }
//             }
//         }
//     }
//     return TotalValue;
// }

int main()
{
    int array[1000];
    int n;
    int i;
    // int x = 10;
    int countValue = 0;
    cout << "enter the number of elements in the array ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "enter the elements %d :";
        cin >> array[i];

        /* code */
    }
    for (i = 0; i < n; i++)
        cout << array[i] << " ";

    for (int i = 0; i < n; i++)
    {
        if (array[i] >= 10)
        {
            countValue++;
        }
    }
    // countValue = increaseDecreaseValue(array, x, n);
    cout << countValue;
    return 0;
}
