#include <iostream>
#include <stdio.h>
using namespace std;

int counter = 0;
GCD(int a, int b)
{
    if (a == 0)
        return b;
    else
    {
        counter++;
        GCD(b % a, a);
    }
}
int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    cout << "GCD: " << GCD(min(num1, num2), max(num1, num2));
    cout << "\nCount: " << counter;
    return 0;
}
