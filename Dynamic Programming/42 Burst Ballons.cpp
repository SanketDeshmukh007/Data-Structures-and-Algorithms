#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int start, int end)
{
    // Base Case
    if (start > end)
        return 0;

    int coins = INT_MIN;
    for (int i = start; i <= end; i++)
    {
        coins = max(coins, (nums[start - 1] * nums[i] * nums[end + 1] +
                            solve(nums, start, i - 1) + solve(nums, i + 1, end)));
    }
    return coins;
}

int solveMem(vector<int> &nums, int start, int end, vector<vector<int>> &dp)
{
    // Base Case
    if (start > end)
        return 0;

    if (dp[start][end] != -1)
        return dp[start][end];

    int coins = INT_MIN;
    for (int i = start; i <= end; i++)
    {
        coins = max(coins, (nums[start - 1] * nums[i] * nums[end + 1] +
                            solveMem(nums, start, i - 1, dp) + solveMem(nums, i + 1, end, dp)));
    }
    return dp[start][end] = coins;
}

int solveTab(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int start = (n - 2); start >= 1; start--)
    {
        for (int end = start; end <= (n - 2); end++)
        {
            int coins = INT_MIN;
            for (int i = start; i <= end; i++)
            {
                coins = max(coins, (nums[start - 1] * nums[i] * nums[end + 1] +
                                    dp[start][i - 1] + dp[i + 1][end]));
            }
            dp[start][end] = coins;
        }
    }
    return dp[1][n - 2];
}

int maxCoins(vector<int> &nums)
{
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    // int n = nums.size();
    // int start = 1;
    // int end = n - 2;
    // 1. Recursion
    // return solve(nums,start,end);
    // 2. Memoization
    // vector<vector<int>> dp(n,vector<int>(n,-1));
    // return solveMem(nums,start,end,dp);
    // 3. Tabulation
    return solveTab(nums);
}

int main()
{
    //

    return 0;
}