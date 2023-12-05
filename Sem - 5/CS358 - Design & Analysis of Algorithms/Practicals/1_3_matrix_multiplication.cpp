#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    cout << "Enter m*n for matrix 1: " << endl;
    int m, n;
    cin >> m >> n;

    cout << "Enter x*y for matrix 1: " << endl;
    int x, y;
    cin >> x >> y;

    int a[m][n];
    int b[x][y];
    int ans[m][y];

    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < y; j++)
        {
            ans[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < n; k++)
            {
                count++;
                ans[i][j] = ans[i][j] + (a[i][k] * b[k][j]);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << ans[i][j] << " ";
        }
    }
    cout << "Count: " << count;
    return 0;
}
