#include <bits/stdc++.h>
using namespace std;

int trailingZeroes(int n)
{
    int ans = 0;

    while(n != 0)
    {
        ans = ans + (n / 5);

        n = n / 5;
    }
    return ans;
}

int main()
{
    cout << trailingZeroes(625) << endl;

    return 0;
}