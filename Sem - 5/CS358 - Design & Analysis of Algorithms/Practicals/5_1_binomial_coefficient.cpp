#include <iostream>
using namespace std;

int BNMCOEFIterative(int n, int k)
{
    int mat[n + 1][k + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            // i = n, j = k
            if (i == j || j == 0)
            {
                mat[i][j] = 1;
            }
            else if (i > j)
            {
                mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
            }
            else // n < k
            {
                mat[i][j] = 0;
            }
        }
    }

    cout << "Matrix..." << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            cout << mat[i][j] << "     ";
        }
        cout << endl;
    }

    return mat[n][k];
}

int BNMCOEF(int n, int k)
{
    int mat[n][k];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (n == k || k == 0)
            {
                mat[i][j] = 1;
                return 1;
            }
            else if (n > k)
            {
                return (BNMCOEF(n - 1, k - 1) + BNMCOEF(n - 1, k));
            }
            else // n < k
            {
                mat[i][j] = 0;
            }
        }
    }
}

int main()
{
    int n, k;
    cout << "Enter n and k : ";
    cin >> n >> k;
    cout << endl
         << "Recursive..." << endl;
    cout << "C(" << n << "," << k << ") = " << BNMCOEF(n, k) << endl;

    cout << endl
         << "Iterative..." << endl;

    int res = BNMCOEFIterative(n, k);
    cout << "C(" << n << "," << k << ") = " << res << endl
         << endl;

    return 0;
}
