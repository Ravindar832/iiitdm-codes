#include<iostream>
#include<math.h>
using namespace std;


int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = pow(2,20);
    int count;
 
    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k)
                + MatrixChainOrder(p, k + 1, j)
                + p[i - 1] * p[k] * p[j];
 
        if (count < min)
            min = count;
    }
 
    return min;
}
 
int main()
{
    int n;
    cout << "\nENTER NUMBER OF MATRICES IN THE CHAIN\n";
  cin >> n;
  int array[n + 1];

  cout << "\n Enter coloums of the chain and coloum and row of the last matrix";
  for (int i = 0; i < n ; i++)
  {
    cin >> array[i];
  }
 
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(array, 1, n - 1);

    return 0;
}
 


