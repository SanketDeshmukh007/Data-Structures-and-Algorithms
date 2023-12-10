#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
// TC - O(3^N) and SC - O(N)
int solve(vector<int> &days, vector<int> &costs, int i)
{
    if (i >= days.size())
        return 0;

    // 1 Day
    int cost1 = costs[0] + solve(days, costs, i + 1);

    // 7 Day
    int passEndDate = days[i] + 6;
    int j = i;
    while (j < days.size() and days[j] <= passEndDate)
    {
        j++;
    }
    int cost7 = costs[1] + solve(days, costs, j);

    // 30 Day
    passEndDate = days[i] + 29;
    j = i;
    while (j < days.size() and days[j] <= passEndDate)
    {
        j++;
    }
    int cost30 = costs[2] + solve(days, costs, j);

    return min(cost1, min(cost7, cost30));
}

// 2. Memoization
int solveMem(vector<int> &days, vector<int> &costs, int i, vector<int> &dp)
{
    if (i >= days.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];

    // 1 Day
    int cost1 = costs[0] + solveMem(days, costs, i + 1, dp);

    // 7 Day
    int passEndDate = days[i] + 6;
    int j = i;
    while (j < days.size() and days[j] <= passEndDate)
    {
        j++;
    }
    int cost7 = costs[1] + solveMem(days, costs, j, dp);

    // 30 Day
    passEndDate = days[i] + 29;
    j = i;
    while (j < days.size() and days[j] <= passEndDate)
    {
        j++;
    }
    int cost30 = costs[2] + solveMem(days, costs, j, dp);

    dp[i] = min(cost1, min(cost7, cost30));
    return dp[i];
}

// 3. Tabulation
// TC - O(N) and SC - O(N)
int solveTab(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        // 1 Day
        int cost1 = costs[0] + dp[i + 1];

        // 7 Day
        int passEndDate = days[i] + 6;
        int j = i;
        while (j < days.size() and days[j] <= passEndDate)
        {
            j++;
        }
        int cost7 = costs[1] + dp[j];

        // 30 Day
        passEndDate = days[i] + 29;
        j = i;
        while (j < days.size() and days[j] <= passEndDate)
        {
            j++;
        }
        int cost30 = costs[2] + dp[j];

        dp[i] = min(cost1, min(cost7, cost30));
    }

    return dp[0];
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int i = 0;
    // 1. Recursion
    // return solve(days,costs,i);

    // 2. Memoization
    // int n = days.size();
    // vector<int> dp(n+1,-1);
    // return solveMem(days,costs,i,dp);

    // 3. Tabulation
    return solveTab(days, costs);
}

int main()
{
    //

    return 0;
}