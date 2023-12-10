#include <bits/stdc++.h>
using namespace std;

int solve(string &s, string &t, int i, int j)
{
    if (i == s.size() and j != t.size())
        return 0;
    if (j == t.size())
        return 1;

    int ans = 0;
    if (s[i] == t[j])
        ans += solve(s, t, i + 1, j + 1);

    ans += solve(s, t, i + 1, j);

    return ans;
}

int solveMem(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    if (i == s.size() and j != t.size())
        return 0;
    if (j == t.size())
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (s[i] == t[j])
        ans += solveMem(s, t, i + 1, j + 1, dp);

    ans += solveMem(s, t, i + 1, j, dp);

    return dp[i][j] = ans;
}

int numDistinct(string s, string t)
{
    // 1. Recursion
    // return solve(s,t,0,0);
    // 2. Memoization
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solveMem(s, t, 0, 0, dp);
}

int main()
{
    //

    return 0;
}