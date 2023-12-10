#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> a, vector<int> b)
{
    if (a[0] >= b[0] and a[1] >= b[1] and a[2] >= b[2])
        return true;

    return false;
}

// 1. Recursion
// TC - O(Exponential)
int lengthOfLISRec(vector<vector<int>> &nums, int curr, int prev)
{
    if (curr >= nums.size())
        return 0;

    // include
    int include = 0;
    if (prev == -1 or check(nums[curr], nums[prev]))
        include = nums[curr][2] + lengthOfLISRec(nums, curr + 1, curr);
    // exclude
    int exclude = 0 + lengthOfLISRec(nums, curr + 1, prev);

    int ans = max(include, exclude);
    return ans;
}

// 2. Top Down Approach
int lengthOfLISMem(vector<vector<int>> &nums, int curr, int prev, vector<vector<int>> &dp)
{
    if (curr >= nums.size())
        return 0;
    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    // include
    int include = 0;
    if (prev == -1 or check(nums[curr], nums[prev]))
        include = nums[curr][2] + lengthOfLISRec(nums, curr + 1, curr);
    // exclude
    int exclude = 0 + lengthOfLISRec(nums, curr + 1, prev);

    dp[curr][prev + 1] = max(include, exclude);
    return dp[curr][prev + 1];
}

int maxHeight(vector<vector<int>> &cuboids)
{

    for (auto &x : cuboids)
        sort(x.begin(), x.end());

    sort(cuboids.begin(), cuboids.end());

    for (auto x : cuboids)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    int curr = 0;
    int prev = -1;

    // 1. Recursion
    // return lengthOfLISRec(cuboids,curr,prev);

    // 2. Top Down Approach
    int n = cuboids.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return lengthOfLISMem(cuboids, curr, prev, dp);
}

int main()
{
    //

    return 0;
}