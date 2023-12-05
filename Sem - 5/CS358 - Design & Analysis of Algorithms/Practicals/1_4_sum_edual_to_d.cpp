#include <iostream>
#include <vector>

using namespace std;

bool subsequenceSum(vector<int> const &arr, int n, int k)
{
    if (k == 0)
    {
        return true;
    }
    if (n < 0 || k < 0)
    {
        return false;
    }
    bool include = subsequenceSum(arr, n - 1, k - arr[n]);
    bool exclude = subsequenceSum(arr, n - 1, k);
    return include || exclude;
}

int main()
{

    vector<int> A = {1, 2, 5, 6, 8};
    int k = 9;

    int n = A.size();
    if (subsequenceSum(A, n - 1, k))
    {
        cout << "\nSubsequence with the given sum exists\n"
             << endl;
    }
    else
    {
        cout << "\nSubsequence with the given sum does not exist" << endl;
    }
    return 0;
}
