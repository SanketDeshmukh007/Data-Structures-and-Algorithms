#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

int GCD1(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (a > 0 and b > 0)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    (a == 0) ? b : a;
}

int main()
{
    cout << GCD(24, 72) << endl;
    // Inbuilt Function
    cout << gcd(24, 72) << endl;

    return 0;
}