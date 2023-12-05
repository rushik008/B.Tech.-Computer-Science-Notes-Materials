#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    long long n, fact = 1, i = 0, count = 0;
    cout << "Enter a number : ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        fact = fact * i;
        count++;
    }
    cout << "Factorial: " << fact << endl;
    cout << "Count: " << count << endl;
    return 0;
}