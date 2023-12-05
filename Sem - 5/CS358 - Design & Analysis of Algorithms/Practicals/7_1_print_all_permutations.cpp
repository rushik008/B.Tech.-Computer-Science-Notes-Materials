#include <stdio.h>
#include <iostream>

#define F first
#define S second
#define pb push_back

using namespace std;

void permute(string a, int l, int r)
{
    if (l == r)
        cout << a << endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l + 1, r);
            swap(a[l], a[i]);
        }
    }
}

int main()
{
    string str;
    cout << "Enter a string : ";
    cin >> str;
    int n = str.size();
    cout << "Permutations..." << endl;
    permute(str, 0, n - 1);
    cout << endl;
    return 0;
}
