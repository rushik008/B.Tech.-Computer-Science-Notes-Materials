#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int b[2][3] = {{7, 8, 9}, {1, 2, 3}};
    int c[2][3];

    int count = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            count++;
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << c[i][j] << endl;
        }
    }
    cout << "Count: " << count;
    return 0;
}
