#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W, int weights[], int values[], int n)
{
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] +
                                  K[i - 1][w - weights[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main()
{
    int sack;
    cout << "Enter number of sack : ";
    cin >> sack;

    int *values = new int[sack];
    int *weights = new int[sack];

    cout << "Enter values and corresponding weights..." << endl;
    for (int i = 0; i < sack; i++)
    {
        cin >> values[i] >> weights[i];
    }

    int w;
    cout << "Enter total weight : ";
    cin >> w;

    int n = sizeof(values) / sizeof(values[0]);
    cout << "Maximum profit : " << knapSack(w, weights, values, n) << endl
         << endl;
    return 0;
}
