#include <bits/stdc++.h>
using namespace std;

int solve(string &s1, string &s2, int i, int j)
{
    int cost = 0;
    // Base Case
    if (i == s1.size() or j == s2.size())
    {
        for (int x = i; x < s1.size(); x++)
            cost += s1[x];
        for (int x = j; x < s2.size(); x++)
            cost += s2[x];
        return cost;
    }

    if (s1[i] == s2[j])
        cost = solve(s1, s2, i + 1, j + 1);
    else
    {
        int cost1 = s1[i] + solve(s1, s2, i + 1, j);
        int cost2 = s2[j] + solve(s1, s2, i, j + 1);
        cost = min(cost1, cost2);
    }
    return cost;
}

int solveMem(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    int cost = 0;
    // Base Case
    if (i == s1.size() or j == s2.size())
    {
        for (int x = i; x < s1.size(); x++)
            cost += s1[x];
        for (int x = j; x < s2.size(); x++)
            cost += s2[x];
        return cost;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        cost = solveMem(s1, s2, i + 1, j + 1, dp);
    else
    {
        int cost1 = s1[i] + solveMem(s1, s2, i + 1, j, dp);
        int cost2 = s2[j] + solveMem(s1, s2, i, j + 1, dp);
        cost = min(cost1, cost2);
    }
    return dp[i][j] = cost;
}

int minimumDeleteSum(string s1, string s2)
{
    // Recursion
    // return solve(s1,s2,0,0);
    // Memoization
    int n = (s1.size() > s2.size()) ? s1.size() : s2.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solveMem(s1, s2, 0, 0, dp);
}

int main()
{
    //

    return 0;
}