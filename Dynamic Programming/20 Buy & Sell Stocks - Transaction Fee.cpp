#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
int solve(int index, int buy, vector<int> &prices, int fee)
{
    if (index == prices.size())
        return 0;

    int profit = 0;

    if (buy)
    {
        int Buy = -prices[index] + solve(index + 1, 0, prices, fee);
        int skip = 0 + solve(index + 1, 1, prices, fee);
        profit = max(Buy, skip);
    }
    else
    {
        int sell = prices[index] + solve(index + 1, 1, prices, fee) - fee;
        int skip = 0 + solve(index + 1, 0, prices, fee);
        profit = max(sell, skip);
    }

    return profit;
}

// 2. Memoization
int solveMem(int index, int buy, vector<int> &prices, vector<vector<int>> &dp, int fee)
{
    if (index == prices.size())
        return 0;
    if (dp[index][buy] != -1)
        return dp[index][buy];

    int profit = 0;

    if (buy)
    {
        int Buy = -prices[index] + solveMem(index + 1, 0, prices, dp, fee);
        int skip = 0 + solveMem(index + 1, 1, prices, dp, fee);
        profit = max(Buy, skip);
    }
    else
    {
        int sell = prices[index] + solveMem(index + 1, 1, prices, dp, fee) - fee;
        int skip = 0 + solveMem(index + 1, 0, prices, dp, fee);
        profit = max(sell, skip);
    }

    dp[index][buy] = profit;
    return dp[index][buy];
}

// 3. Tabulation
int solveTab(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // -1
    // dp[n][1] = 0;

    for (int index = n - 1; index >= 0; index--)
    {
        int profit = 0;
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                int Buy = -prices[index] + dp[index + 1][0];
                int skip = 0 + dp[index + 1][1];
                profit = max(Buy, skip);
            }
            else
            {
                int sell = prices[index] + dp[index + 1][1] - fee;
                int skip = 0 + dp[index + 1][0];
                profit = max(sell, skip);
            }

            dp[index][buy] = profit;
        }
    }

    return dp[0][1];
}

// 4. Space Optimization
// TC - O(N) and SC - O(1)
int solveSO(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        int profit = 0;
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                int Buy = -prices[index] + next[0];
                int skip = 0 + next[1];
                profit = max(Buy, skip);
            }
            else
            {
                int sell = prices[index] + next[1] - fee;
                int skip = 0 + next[0];
                profit = max(sell, skip);
            }

            curr[buy] = profit;
        }
        next = curr;
    }

    return next[1];
}
int maxProfit(vector<int> &prices, int fee)
{
    // 1. Recursion
    // return solve(0,1,prices,fee);

    // 2. Memoization
    // int n = prices.size();
    // vector<vector<int>> dp(n+1,vector<int>(2,-1));
    // return solveMem(0,1,prices,dp,fee);

    // 3. Tabulation
    // return solveTab(prices,fee);

    // 4. Space Optimization
    return solveSO(prices, fee);
}

int main()
{
    //

    return 0;
}