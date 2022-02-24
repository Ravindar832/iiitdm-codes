#include <iostream>
using namespace std;

class Two_Stacks
{
    int *arr;
    int size;
    int top_1;
    int top_2;

public:
    Two_Stacks(int n)
    {
        size = n;
        arr = new int[n];
        top_1 = -1;
        top_2 = n / 2 + 1;
    }
    void push_1(int x);
    void push_2(int x);
    int pop_1();
    int pop_2();
};

// Driver code
int main()
{
    int Number, choice, n;
    cout << "Enter the size of array :\n";
    cin >> n;
    Two_Stacks T1(n);
    while (1)
    {
        cout << "1. Push an element in to first stack\n2. Push an element in to second stack\n3. pop an element from first stack and display it\n4. pop an element from second stack and display it\n5. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> Number;
            T1.push_1(Number);
            break;
        case 2:
            cin >> Number;
            T1.push_2(Number);
            break;
        case 3:
            cout << "******popped Number in first stack is : \n"
                 << T1.pop_1();
            break;
        case 4:
            cout << "******popped Number in second stack is : \n"
                 << T1.pop_2();
            break;
        default:
            exit(1);
        }
    }
    return 0;
}

void Two_Stacks::push_1(int x)
{
    if (top_1 >= ((size / 2) - 1))
    {
        cout << "----------Stack Overflow------\n";
    }
    else
    {
        arr[++top_1] = x;
        cout << x << " pushed into stack\n";
    }
}

void Two_Stacks::push_2(int x)
{
    if (top_2 < size + 1)
    {
        top_2++;
        arr[top_2] = x;
    }
    else
    {
        cout << "----Stack Overflow"
             << " By element :" << x << endl;
        return;
    }
}

int Two_Stacks::pop_1()
{
    if (top_1 < 0)
    {
        cout << "------------Stack Underflow------------\n";
        return -1;
    }
    else
    {
        int x = arr[top_1--];
        return x;
    }
}

int Two_Stacks::pop_2()
{
    if (top_2 < size / 2)
    {
        cout << "----------Stack Underflow--------------\n";
        return -1;
    }
    else
    {
        int x = arr[top_2--];
        return x;
    }
}