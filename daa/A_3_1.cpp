#include <iostream>
using namespace std;

class Different_way_approach
{
    int arr[1000];
    int n;

public:
    int One_Way(int arr[], int n)
    {
        int maximum = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > maximum)
                maximum = arr[i];
        }
        return maximum;
    }

    int Two_Way(int left, int right, int arr[])
    {
        if (right == left)
            return arr[right];
        int mid = (right + left) / 2, Left_side, Right_side;
        Left_side = Two_Way(left, mid, arr);
        Right_side = Two_Way(mid + 1, right, arr);
        if (Left_side > Right_side)
            return Left_side;
        else
            return Right_side;
    }

    int Three_Way(int left, int right, int arr[])
    {
        if (left == right)
            return arr[right];
        else if (left > right)
            return 0;
        else
        {
            int n = (right - left + 1);
            int maximum = 0;
            int left_side[3];
            int right_side[3];
            for (int i = 0; i < 3; ++i)
            {
                if (i == 0)
                {
                    left_side[i] = left;
                }
                else
                {
                    left_side[i] = right_side[i - 1] + 1;
                }

                if (n % 3 > i)
                {
                    right_side[i] = left_side[i] + n / 3;
                }
                else
                {
                    right_side[i] = left_side[i] + (n / 3) - 1;
                }
                int temp = Three_Way(left_side[i], right_side[i], arr);
                if (temp > maximum)
                {
                    maximum = temp;
                }
            }
            return maximum;
        }
    }

    int K_way(int left, int right, int k, int arr[])
    {
        if (left == right)
            return arr[right];
        else if (left > right)
            return 0;
        else
        {
            int n = (right - left + 1);
            int maximum = 0;
            int left_side[k];
            int right_side[k];
            for (int i = 0; i < k; ++i)
            {
                if (i == 0)
                {
                    left_side[i] = left;
                }
                else
                {
                    left_side[i] = right_side[i - 1] + 1;
                }

                if (n % k > i)
                {
                    right_side[i] = left_side[i] + n / k;
                }
                else
                {
                    right_side[i] = left_side[i] + (n / k) - 1;
                }
                int temp = K_way(left_side[i], right_side[i], k, arr);
                if (temp > maximum)
                {
                    maximum = temp;
                }
            }
            return maximum;
        }
    }
};

int main()
{
    Different_way_approach W1;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int choice, k;
    while (1)
    {
        cout << " 1.One way\n 2.Two way\n 3.Three way\n 4.K way\n 5.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "maximum in 1-way is:" << endl;
            cout << W1.One_Way(arr, n) << "\n";
            break;
        case 2:
            cout << "maximum in 2-way is:" << endl;
            cout << W1.Two_Way(0, n - 1, arr) << "\n";
            break;
        case 3:
            cout << "maximum in 3-way is:" << endl;
            cout << W1.Three_Way(0, n - 1, arr) << endl;
            break;
        case 4:
            cout << "Enter the value of k: ";
            cin >> k;
            if (k > 1)
            {
                cout << "maximum in k-way is:" << endl;
                cout << W1.K_way(0, n - 1, k, arr) << endl;
            }
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}