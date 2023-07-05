#include <bits/stdc++.h>
using namespace std;

long long int PowMod(long long int x, long long int n, long long int M)
{
    long long int ans = 1;

    while (n > 0)
    {
        if (n & 1)
            ans = (ans % M) * ((x % M));

        x = (x % M) * (x % M);
        n = n >> 1;
    }

    return (ans % M);
}

int main()
{
    long long int x = 2, n = 6, m = 10;
    cout << PowMod(x,n,m) << endl;

    return 0;
}