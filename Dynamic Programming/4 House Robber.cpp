#include <bits/stdc++.h>
using namespace std;

// 1. Using Recursion
// n --> Index of current house
// TC -- O(Exponential) and SC -- O(N)
int rec(vector<int> &nums, int n)
{
    // Base Case
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];

    // Include
    int include = rec(nums, n - 2) + nums[n];
    // Exclude
    int exclude = rec(nums, n - 1);

    return max(include, exclude);
}

// 2. Top Down = Rec + Memoization
// TC -- O(N) and SC -- O(N)
int memo(vector<int> &nums, int n, vector<int> &dp)
{
    // Base Case
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];
    if (dp[n] != -1)
        return dp[n];

    // Include
    int include = memo(nums, n - 2, dp) + nums[n];
    // Exclude
    int exclude = memo(nums, n - 1, dp);

    dp[n] = max(include, exclude);
    return dp[n];
}

// 3. Bottom Up -- Tabulation Method
// TC -- O(N) and SC -- O(N)
int tab(vector<int> &nums, int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = nums[0];

    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        if (i - 2 >= 0)
            temp = dp[i - 2];
        int include = temp + nums[i];
        int exclude = dp[i - 1];

        dp[i] = max(include, exclude);
    }
    return dp[n];
}

// 4. Space Optimization
// TC -- O(N) and SC -- O(1)
int spaceOpt(vector<int> &nums, int n)
{
    int prev2 = 0;
    int prev1 = nums[0];
    int curr;

    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        if (i - 2 >= 0)
            temp = prev2;
        int include = temp + nums[i];
        int exclude = prev1;

        curr = max(include, exclude);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int rob(vector<int> &nums)
{
    int n = nums.size() - 1;
    // return rec(nums,n);

    // 2. Top Down
    // vector<int> dp(n+1,-1);
    // return memo(nums,n,dp);

    // 3. Bottom Up
    // return tab(nums,n);

    // 4. Space Optimization
    return spaceOpt(nums, n);
}

int main()
{
    //

    return 0;
}