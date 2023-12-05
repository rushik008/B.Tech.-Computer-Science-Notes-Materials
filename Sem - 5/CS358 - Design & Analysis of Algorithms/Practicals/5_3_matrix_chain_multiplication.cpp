#include <stdio.h>
#include <iostream>
#include <set>
#include <cstring>

#define F first
#define S second
#define pb push_back

using namespace std;

int dp[100][100];

// Function for matrix chain multiplication
int matrixChainMemoised(int *p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    dp[i][j] = 2147483647;

    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(
            dp[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}

int MatrixChainOrder(int *p, int n)
{
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}

int main()
{
    int arr_size;
    cin >> arr_size;
    int *arr = new int[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);
    cout << "Minimum number of multiplications is: " << MatrixChainOrder(arr, n) << endl;
    return 0;
}
