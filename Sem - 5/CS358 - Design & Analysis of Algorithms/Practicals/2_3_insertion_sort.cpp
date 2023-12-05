#include <stdio.h>
#include <iostream>
using namespace std;

int count = 0;

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			count++;
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		count++;
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int n;
	cout << "Enter the length: ";
	cin >> n;
	int *arr = new int[n];

	cout << "Enter an array elements: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << "Array: ";
	printArray(arr, n);

	insertionSort(arr, n);
	cout << "Sorted: ";
	printArray(arr, n);
	cout << "Count: " << count << endl;
	return 0;
}
