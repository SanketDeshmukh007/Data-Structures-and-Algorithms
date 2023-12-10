#include <bits/stdc++.h>
using namespace std;

// Recursive Solution -- TLE
// TC -- O(N^N) and SC -- O(N)
int Rec(vector<int> &coins, int amount)
{
    // Base Case
    if (amount == 0)
        return 0;
    if (amount < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = Rec(coins, amount - coins[i]);
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans);
    }
    return mini;
}

// Top Down Approach -- Recursion + Memoization
// TC -- O(amount) and SC -- O(N)
int topDown(vector<int> &coins, int amount, vector<int> &dp)
{
    // Base Case
    if (amount == 0)
        return 0;
    if (amount < 0)
        return INT_MAX;
    if (dp[amount] != -1)
        return dp[amount];

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = topDown(coins, amount - coins[i],dp);
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans);
    }
    dp[amount] = mini;
    return dp[amount];
}

// Bottom UP Approach -- Tabulation Method
int bottomUp(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX); // We are storing min values thats why INT_MAX
    // Base Case
    dp[0] = 0;

    for (int target = 1; target <= amount; target++)
    {
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (target - coins[i] >= 0)
            {
                int ans = dp[target - coins[i]];
                if (ans != INT_MAX)
                    mini = min(mini, 1 + ans);
            }
        }
        dp[target] = mini;
    }
    return dp[amount];
}

int coinChange(vector<int> &coins, int amount)
{
    // 1. Recursive Solution
    // int ans =  Rec(coins,amount);
    // if(ans == INT_MAX) return -1;
    // return ans;

    // 2. Top Down Approach
    // int n = amount;
    // vector<int> dp(n+1,-1);
    // int ans = topDown(coins,amount,dp);
    // if(ans != INT_MAX) return ans;
    // return -1;

    // 3. Bottom Approach
    int ans = bottomUp(coins, amount);
    if (ans != INT_MAX)
        return ans;
    return -1;
}

int main()
{
    //

    return 0;
}