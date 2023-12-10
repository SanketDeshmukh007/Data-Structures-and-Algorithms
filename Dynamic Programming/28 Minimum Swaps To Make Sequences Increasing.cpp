#include <bits/stdc++.h>
using namespace std;

// p -> previous
int solve(vector<int> &nums1, vector<int> &nums2, int i, int p1, int p2)
{
    if (i == nums1.size())
        return 0;

    int swap = INT_MAX, noSwap = INT_MAX;
    // swap
    if (p1 < nums2[i] and p2 < nums1[i])
        swap = 1 + solve(nums1, nums2, i + 1, nums2[i], nums1[i]);
    // noSwap
    if (p1 < nums1[i] and p2 < nums2[i])
        noSwap = solve(nums1, nums2, i + 1, nums1[i], nums2[i]);

    return min(swap, noSwap);
}

int solveMem(vector<int> &nums1, vector<int> &nums2, int i, int p1, int p2, vector<vector<int>> &dp, int isSwap)
{
    if (i == nums1.size())
        return 0;
    if (dp[i][isSwap] != -1)
        return dp[i][isSwap];

    int swap = INT_MAX, noSwap = INT_MAX;
    // swap
    if (p1 < nums2[i] and p2 < nums1[i])
        swap = 1 + solveMem(nums1, nums2, i + 1, nums2[i], nums1[i], dp, 1);
    // noSwap
    if (p1 < nums1[i] and p2 < nums2[i])
        noSwap = solveMem(nums1, nums2, i + 1, nums1[i], nums2[i], dp, 0);

    dp[i][isSwap] = min(swap, noSwap);
    return dp[i][isSwap];
}

int solveTab(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j >= 0; j--)
        {
            int swap = INT_MAX, noSwap = INT_MAX;
            int p1 = (i - 1 >= 0) ? nums1[i - 1] : -1;
            int p2 = (i - 1 >= 0) ? nums2[i - 1] : -1;

            if (j)
            {
                std::swap(p1, p2);
            }
            // swap
            if (p1 < nums2[i] and p2 < nums1[i])
                swap = 1 + dp[i + 1][1];
            // noSwap
            if (p1 < nums1[i] and p2 < nums2[i])
                noSwap = dp[i + 1][0];

            dp[i][j] = min(swap, noSwap);
        }
    }
    return dp[0][0];
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    // 1. Recursion
    // return solve(nums1,nums2,0,-1,-1);

    // 2. Memoization
    // int n = nums1.size();
    // vector<vector<int>> dp(n+1,vector<int>(2,-1));
    // return solveMem(nums1,nums2,0,-1,-1,dp,0);

    // 3. Tabulation
    return solveTab(nums1, nums2);
}

int main()
{
    //

    return 0;
}