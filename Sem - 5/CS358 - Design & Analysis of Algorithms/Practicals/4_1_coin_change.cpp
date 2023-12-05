#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, amount;
    cout << "Enter the coins for denomination : ";
    cin >> n;
    int *C = new int[n];

    cout << "Enter denominations coins : ";
    for (int i = 0; i < n; i++)
    {
        cin >> C[i];
    }

    cout << "Enter amount : ";
    cin >> amount;
    sort(C, C + n, greater<int>());
    vector<int> solution;
    int x = C[0];
    int j = 0;
    while (amount > 0 && j < n)
    {
        if (amount >= x && amount > 0)
        {
            solution.push_back(x);
            amount -= x;
        }
        else
        {
            j++;
            x = C[j];
        }
    }
    cout << "Total coins required : " << solution.size();
    cout << "\nCoins are : ";
    for (auto x : solution)
    {
        cout << x << " ";
    }
    return 0;
}
