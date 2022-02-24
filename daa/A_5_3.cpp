#include <iostream>
using namespace std;

class Dictionary_order
{
private:
    string str[1000];
    int n;

public:
    void Bubble_sorting_words(string str[], int n)
    {
        string temp;
        // Use Bubble Sort to arrange words
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (str[j] > str[j + 1])
                {
                    temp = str[j];
                    str[j] = str[j + 1];
                    str[j + 1] = temp;
                }
            }
        }
    }
};

int main()
{
    Dictionary_order D_1;
    int n;
    cout << "Enter the size of array of strings: " << endl;
    cin >> n;
    string string_array[n + 1], temp;

    cout << "Enter " << n << " words: " << endl;
    for (int i = 0; i < n + 1; ++i)
    {
        getline(cin, string_array[i]);
    }

    D_1.Bubble_sorting_words(string_array, n + 1);

    cout << "--------------The Dictionary order of above words are--------------------" << endl;

    for (int i = 1; i < n + 1; ++i)
    {
        cout << i << ")."
             << " " << string_array[i] << endl;
    }
    return 0;
}