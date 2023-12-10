#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &stoneValue, int i)
{
    if (i == stoneValue.size())
        return 0;

    int ans = INT_MIN;
    int total = 0;
    for (int x = 1; x <= 3; x++)
    {
        if (i + x - 1 >= stoneValue.size())
            break;
        total += stoneValue[i + x - 1];

        ans = max(ans, total - solve(stoneValue, i + x));
    }
    return ans;
}

int solveMem(vector<int> &stoneValue, int i, vector<int> &dp)
{
    if (i == stoneValue.size())
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int ans = INT_MIN;
    int total = 0;
    for (int x = 1; x <= 3; x++)
    {
        if (i + x - 1 >= stoneValue.size())
            break;
        total += stoneValue[i + x - 1];

        ans = max(ans, total - solveMem(stoneValue, i + x, dp));
    }
    return dp[i] = ans;
}

int solveTab(vector<int> &stoneValue)
{
    int n = stoneValue.size();
    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        int ans = INT_MIN;
        int total = 0;
        for (int x = 1; x <= 3; x++)
        {
            if (i + x - 1 >= stoneValue.size())
                break;
            total += stoneValue[i + x - 1];

            ans = max(ans, total - dp[i + x]);
        }
        dp[i] = ans;
    }
    return dp[0];
}

string stoneGameIII(vector<int> &stoneValue)
{
    // 1. Recursion
    // int ans = solve(stoneValue,0);

    // 2. Memoization
    // int n = stoneValue.size();
    // vector<int> dp(n+1,-1);
    // int ans = solveMem(stoneValue,0,dp);

    // 3. Tabulation
    int ans = solveTab(stoneValue);

    if (ans > 0)
        return "Alice";
    else if (ans < 0)
        return "Bob";
    return "Tie";
}

int main()
{
    //

    return 0;
}