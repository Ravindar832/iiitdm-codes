#include<iostream>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void printBinary(int value, int length) {
  for (int i = (length - 1); i >= 0; i--) cout << ((value >> i) & 1 ? 1 : 0);
}

int* decimalToBinary(int value, int length) {
  int* binaryArr = new int[length];

  for (int i = 0; i < length; i++) binaryArr[i] = (value >> i) & 1 ? 1 : 0;

  int start = 0;
  int end = length - 1;

  while (start < end) {
    int temp = binaryArr[start];
    binaryArr[start] = binaryArr[end];
    binaryArr[end] = temp;

    start++;
    end--;
  }

  return binaryArr;
}

int binToDec(int* arr) {
  int decimalValue = 0;
  int base = 1;

  for (int i = 16; i >= 0; i--) {
    decimalValue += arr[i] * base;
    base *= 2;
  }

  return decimalValue;
}


int* subtractArrayFromArray(int* arr1, int* arr2) {
  int* arr[8];
  int a;
  int b;

  for (int i = 0; i < 8; i++) {
    a = arr1[i];
    b = arr2[i];
    arr[i] = &a - b;
  }

  return *arr;
}


int* mergeArr(int arr1[], int arr2[], int c) {
  int* arr = new int[17];
  arr[0] = c;

  for (int i = 1; i < 9; i++) arr[i] = arr1[i - 1];

  for (int i = 9; i < 17; i++) arr[i] = arr2[i - 9];

  return arr;
}

int main()
{ 
  int m;
  int n;
  int c = 0;
  int acc = 0;


  cout << "enter the value m: ";
  cin >> m;

  cout << "enter the value of n: ";
  cin >> n;

 
  int m_x = m;
  int n_y = n;

 
  cout << " m =  " << m << " and ";
  printBinary(m, 8);
  cout << " binary\n";
  cout << " n =  " << n << " and ";
  printBinary(n, 8);
  cout << " binary\n";
  
  int* acc_arr = decimalToBinary(acc, 8);
  int* m_arr = decimalToBinary(m, 8);
  int* n_arr = decimalToBinary(n, 8);

  int step = 1;

  
  while (step < 9) {
    acc_arr = decimalToBinary(acc, 8);

    m_arr = decimalToBinary(m, 8);

    
    n_arr = decimalToBinary(n, 8);

    
    if (m_arr[7] == 1) acc += n;

    
    if (acc >= 256) {
      c = 1;
      acc -= 256;
    }

    
    int* acc_arr = decimalToBinary(acc, 8);
    int* m_arr = decimalToBinary(m, 8);
    int* n_arr = decimalToBinary(n, 8);

   
    int* full_arr = mergeArr(acc_arr, m_arr, c);

    
    int full_int = binToDec(full_arr);

    full_int >>= 1;

    full_arr = decimalToBinary(full_int, 17);

    
    m >>= 1;
    if (acc_arr[7] == 1) m += 128;

    m_arr = decimalToBinary(m, 8);

    acc >>= 1;

    if (c == 1) {
      acc += 128;
      c = 0;
    }

    acc_arr = decimalToBinary(acc, 8);
    step++;

    if (step == 9) {
      cout << "\n\n m*n binary representation \n\n";
  
      for (int i = 1; i < 17; i++) cout << full_arr[i];

      cout << "   =     " << (m_x * n_y) << "\n";
    }
  }

  return 0;
}