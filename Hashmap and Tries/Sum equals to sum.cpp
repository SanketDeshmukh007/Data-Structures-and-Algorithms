#include <bits/stdc++.h>
using namespace std;

int findPairs(long long a[], long long n)
{
    unordered_map<int, bool> m;

    for (long long i = 0; i < n; i++)
    {
        int sum = 0;
        for (long long j = i + 1; j < n; j++)
        {
            sum = a[i] + a[j];

            if (m[sum] == true)
                return true;

            m[sum] = true;
        }
    }
    return false;
}

int main()
{
    //

    return 0;
}