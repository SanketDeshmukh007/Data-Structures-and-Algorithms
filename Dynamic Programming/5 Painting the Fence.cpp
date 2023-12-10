#include <bits/stdc++.h>
using namespace std;

#define m 1000000007

long long rec(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    long long ans = (rec(n - 2, k) + rec(n - 1, k)) * (k - 1);
    return (ans % m);
}

long long memo(int n, int k, vector<long long> &dp)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;
    if (dp[n] != -1)
        return dp[n];

    dp[n] = ((memo(n - 2, k, dp) + memo(n - 1, k, dp)) * (k - 1)) % m;
    return dp[n];
}

long long tab(int n, int k)
{
    vector<long long> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = k * k;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((dp[i - 1] + dp[i - 2]) * (k - 1)) % m;
    }
    return dp[n];
}

long long spaceOpt(int n, int k)
{

    long long prev2 = k;
    if (n == 1)
        return prev2;
    long long prev1 = k * k;
    if (n == 2)
        return prev1;
    long long curr = 0;

    for (int i = 3; i <= n; i++)
    {
        curr = ((prev2 + prev1) * (k - 1)) % m;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

long long countWays(int n, int k)
{

    // vector<long long> dp(n+1,-1);
    // return memo(n,k,dp);

    // return tab(n,k);

    return spaceOpt(n, k);
}

int main()
{
    //

    return 0;
}