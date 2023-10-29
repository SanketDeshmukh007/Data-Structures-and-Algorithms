#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (n == 0)
        return false;
    if (n == 1)
        return true;
    if (n < 0)
        return false;

    return (n & (n - 1)) == 0;
}

int main()
{
    //

    return 0;
}