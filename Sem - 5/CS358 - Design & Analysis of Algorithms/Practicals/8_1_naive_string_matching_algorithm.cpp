#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>

#define F first
#define S second
#define pb push_back

using namespace std;

int main()
{
    cout << "Enter string 1: ";
    string S;
    cin >> S;
    int n = S.length();

    cout << "Enter string 2: ";
    string P;
    cin >> P;
    int m = P.length();

    vector<pair<int, int>> M;

    if (m < n)
    {
        for (int i = 0; i < n - m; i++)
        {
            int j;
            for (j = 0; j < m; j++)
            {
                if (S[i + j] != P[j] && P[j] != '*')
                {
                    break;
                }
            }
            if (j == m)
            {
                M.pb(make_pair(i, i + j - 1));
            }
        }
    }
    else
    {
        cout << "Length of pattern string is greater, not possible to match the string to Source" << endl;
    }
    for (auto x : M)
    {
        cout << "Matching positions are found at " << x.first + 1 << " to " << x.second + 1 << endl;
    }
    return 0;
}
