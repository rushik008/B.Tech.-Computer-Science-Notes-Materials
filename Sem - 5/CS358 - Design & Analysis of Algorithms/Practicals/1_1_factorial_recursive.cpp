#include <stdio.h>
#include <iostream>
using namespace std;

int count = 0;

int factorial(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    else
    {
        count++;
        return n * factorial(n - 1);
    }
}

int main()
{
    long long n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Factorial: " << factorial(n) << endl;
    cout << "Count: " << count << endl;
    return 0;
}