#include <iostream>
using namespace std;

void display(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}

int bubbleSort(int arr[], int n)
{
  static int count;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      count++;
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
  return count;
}

int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;

  int *arr = new int[n];
  cout << "Enter array elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << "Array: ";
  display(arr, n);
  cout << endl;
  int count = bubbleSort(arr, n);

  cout << "Sorted: ";
  display(arr, n);
  cout << endl;
  cout << "Count: " << count;
  return 0;
}