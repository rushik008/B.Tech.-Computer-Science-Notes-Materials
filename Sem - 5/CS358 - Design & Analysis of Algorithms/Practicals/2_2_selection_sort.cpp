#include <iostream>
#include <stdio.h>
using namespace std;

int counter = 0;

void swap(int *xp, int *yp)
{
	counter++;
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			counter++;
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}
		swap(&arr[min_idx], &arr[i]);
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

	cout << "Enter array elements: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int arrsize = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, arrsize);
	cout << endl
		 << "Sorted array: ";
	printArray(arr, arrsize);
	cout << "Counter: " << counter;
	return 0;
}
