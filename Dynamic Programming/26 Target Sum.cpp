#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int target, int i)
{
    // Base Case
    if (i == nums.size())
    {
        if (target == 0)
            return 1;
        return 0;
    }

    int ans1 = solve(nums, target + nums[i], i + 1);
    int ans2 = solve(nums, target - nums[i], i + 1);

    return ans1 + ans2;
}

int solveMem(vector<int> &nums, int target, int i, map<pair<int, int>, int> &dp)
{
    // Base Case
    if (i == nums.size())
    {
        if (target == 0)
            return 1;
        return 0;
    }

    if (dp.find({target, i}) != dp.end())
        return dp[{target, i}];

    int ans1 = solveMem(nums, target + nums[i], i + 1, dp);
    int ans2 = solveMem(nums, target - nums[i], i + 1, dp);

    dp[{target, i}] = ans1 + ans2;
    return dp[{target, i}];
}

int findTargetSumWays(vector<int> &nums, int target)
{
    // 1. Recursion
    // return solve(nums,target,0);

    // 2. Memoization
    map<pair<int, int>, int> dp; // {target,i} => ans
    return solveMem(nums, target, 0, dp);
}

int main()
{
    //

    return 0;
}