#include <stdio.h>
#include <iostream>
using namespace std;

double power(long x, long y)
{
    if (y == 0)
    {
        return 1;
    }
    else if (y % 2 == 0)
    {
        return power(x * x, y / 2);
    }
    else
    {
        return x * power(x * x, y / 2);
    }
}

int main()
{
    long x, y;
    cout << "Enter the number and it's power : ";
    cin >> x >> y;
    double result = power(x, y);
    cout << "Result : " << result;
    return 0;
}
