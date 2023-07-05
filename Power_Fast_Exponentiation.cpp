#include <bits/stdc++.h>
using namespace std;

double myPow(double x, long long int n)
{
    double ans = 1;
    int sign = 1;
    if (n < 0)
    {
        sign = -1;
        n = -1 * n;
    }

    while (n > 0)
    {
        if (n & 1)
        {
            ans = ans * x;
        }
        x = x * x;
        n = n >> 1;
    }

    if (sign == -1)
        return 1 / ans;

    return ans;
}

int main()
{
    cout << myPow(10,4) << endl;

    return 0;
}