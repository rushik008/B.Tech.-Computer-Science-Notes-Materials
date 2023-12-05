#include <iostream>
using namespace std;

int counter = 0;

void merge(int arr[], int p, int q, int r)
{
  counter++;
  int n1 = q - p + 1;
  int n2 = r - q;

  int *L = new int[n1];
  int *M = new int[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];

  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i = 0, j = 0, k = p;

  while (i < n1 && j < n2)
  {
    counter++;
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
    counter++;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main()
{
  int n;
  cout << "Enter size of array: ";
  cin >> n;
  int *arr = new int[n];

  for (int i = 0; i < n; i++)
  {
    arr[i] = i + 1;
  }
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  cout << "Sorted array: ";
  printArray(arr, size);
  cout << "Counter:" << counter;
  return 0;
}
