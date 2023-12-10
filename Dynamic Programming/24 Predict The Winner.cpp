#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int start, int end)
{
    if (start == end)
        return nums[start];

    // diff = p1 - p2
    int diffByStart = nums[start] - solve(nums, start + 1, end);
    int diffByEnd = nums[end] - solve(nums, start, end - 1);

    return max(diffByStart, diffByEnd);
}

int solveMem(vector<int> &nums, int start, int end, vector<vector<int>> &dp)
{
    if (start == end)
        return nums[start];

    if (dp[start][end] != -1)
        return dp[start][end];

    // diff = p1 - p2
    int diffByStart = nums[start] - solveMem(nums, start + 1, end, dp);
    int diffByEnd = nums[end] - solveMem(nums, start, end - 1, dp);

    dp[start][end] = max(diffByStart, diffByEnd);
    return dp[start][end];
}

bool predictTheWinner(vector<int> &nums)
{
    // 1. Recursion
    // return solve(nums,0,nums.size()-1) >= 0;

    // 2. Memoization
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solveMem(nums, 0, n - 1, dp) >= 0;
}

int main()
{
    //

    return 0;
}