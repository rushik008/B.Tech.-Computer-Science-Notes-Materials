#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0, count = 1;
    cout << "Enter no of activities : ";
    cin >> n;
    int *arr_start = new int[n];
    int *arr_end = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter start and end time of activity " << i + 1 << " : ";
        cin >> arr_start[i];
        cin >> arr_end[i];
    }

    int i = 0;
    for (int j = 1; j < n; j++)
    {
        // ending of first should be less than or equal to the second for count
        if (arr_end[i] <= arr_start[j])
        {
            count++;
            i = j;
        }
    }

    cout << endl
         << "Max no of activity possible : " << count << endl;
    ;
    return 0;
}
