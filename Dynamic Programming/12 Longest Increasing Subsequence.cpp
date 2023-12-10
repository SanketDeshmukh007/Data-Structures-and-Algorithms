#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
// TC - O(Exponential)
int lengthOfLISRec(vector<int> &nums, int curr, int prev)
{
    if (curr >= nums.size())
        return 0;

    // include
    int include = 0;
    if (prev == -1 or nums[curr] > nums[prev])
        include = 1 + lengthOfLISRec(nums, curr + 1, curr);
    // exclude
    int exclude = 0 + lengthOfLISRec(nums, curr + 1, prev);

    int ans = max(include, exclude);
    return ans;
}

// 2. Top Down Approach
// TC and SC - O(N*2)
int lengthOfLISMem(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
{
    if (curr >= nums.size())
        return 0;
    if (dp[curr][prev + 1] != -1) // prev + 1 --> -1 + 1 = 0
        return dp[curr][prev + 1];

    // include
    int include = 0;
    if (prev == -1 or nums[curr] > nums[prev])
        include = 1 + lengthOfLISRec(nums, curr + 1, curr);
    // exclude
    int exclude = 0 + lengthOfLISRec(nums, curr + 1, prev);

    dp[curr][prev + 1] = max(include, exclude);
    return dp[curr][prev + 1];
}

// TC - O(N * logN) and SC - O(N)
int optimalBinarySearch(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    vector<int> ans;
    ans.push_back(nums[0]);

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > ans.back())
            ans.push_back(nums[i]);
        else
        {
            // overwrite the previous just big element
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[index] = nums[i];
        }
    }
    return ans.size();
}

int lengthOfLIS(vector<int> &nums)
{
    int curr = 0;
    int prev = -1;
    // 1. Recursion
    // return lengthOfLISRec(nums,curr,prev);
    // 2. Top Down Approach
    // int n = nums.size();
    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // return lengthOfLISMem(nums,curr,prev,dp);
    // 3. Binary Search
    return optimalBinarySearch(nums);
}

int main()
{
    //

    return 0;
}