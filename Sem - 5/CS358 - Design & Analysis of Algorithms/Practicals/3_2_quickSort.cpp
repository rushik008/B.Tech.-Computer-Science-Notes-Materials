#include <cstdlib>
#include <stdio.h>
#include <iostream>
using namespace std;

int counter = 0;

void display(long long arr[], long long n)
{
	for (long long i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

void swap(long long arr[], long long pos1, long long pos2)
{
	long long temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

long long partition(long long arr[], long long low, long long high, long long pivot)
{
	long long i = low;
	long long j = low;

	while (i <= high)
	{
		counter++;
		if (arr[i] > pivot)
		{
			i++;
		}
		else
		{
			swap(arr, i, j);
			i++;
			j++;
		}
	}
	return j - 1;
}

void quickSort(long long arr[], long long low, long long high)
{
	if (low < high)
	{
		counter++;
		long long pivot = arr[high];
		long long pos = partition(arr, low, high, pivot);

		quickSort(arr, low, pos - 1);
		quickSort(arr, pos + 1, high);
	}
}

int main()
{
	long long n;
	cout << "Enter the size of array";
	cin >> n;
	long long *arr = new long long[n];
	// long long arr[n];

	// for worst case
	// for (int i = 0; i < n; i++)
	// {
	// 	arr[i] = i + 1;
	// }

	// for average case
	for (long long i = 0; i < n; i++)
	{
		arr[i] = rand();
	}

	cout << endl
		 << "Array: ";
	display(arr, n);

	quickSort(arr, 0, n - 1);
	cout << endl
		 << "The sorted array is: ";
	display(arr, n);

	cout << endl
		 << "Counter is: " << counter << endl;

	return 0;
}
