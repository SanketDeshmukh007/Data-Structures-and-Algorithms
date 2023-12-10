#include <bits/stdc++.h>
using namespace std;

// 1. Using Recursion
// n --> Index of current house
// TC -- O(Exponential) and SC -- O(N)
int rec(vector<int> &nums, int i, int n)
{
    // Base Case
    if (i >= n)
        return 0;

    // Include
    int include = rec(nums, i + 2, n) + nums[i];
    // Exclude
    int exclude = rec(nums, i + 1, n);

    return max(include, exclude);
}

// 2. Top Down = Rec + Memoization
// TC -- O(N) and SC -- O(N)
int memo(vector<int> &nums, int i, int n, vector<int> &dp)
{
    // Base Case
    if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    // Include
    int include = rec(nums, i + 2, n) + nums[i];
    // Exclude
    int exclude = rec(nums, i + 1, n);

    return max(include, exclude);

    dp[i] = max(include, exclude);
    return dp[i];
}

int rob(vector<int> &nums)
{
    // int n = nums.size()-1;
    // int ans1 = rec(nums,0,n);
    // n = nums.size();
    // int ans2 = rec(nums,1,n);
    // return max(ans1,ans2);

    // 2. Top Down
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    n = nums.size() - 1;
    int ans1 = memo(nums, 0, n, dp);
    n = nums.size();
    int ans2 = memo(nums, 1, n, dp);
    return max(ans1, ans2);
}

int main()
{
    //

    return 0;
}