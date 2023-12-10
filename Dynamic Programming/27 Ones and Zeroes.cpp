#include <bits/stdc++.h>
using namespace std;

void convert(vector<string> &strs, vector<pair<int, int>> &nums)
{
    for (auto x : strs)
    {
        int countZero = 0;
        int countOne = 0;

        for (auto y : x)
        {
            if (y == '0')
                countZero++;
            else
                countOne++;
        }

        nums.push_back({countZero, countOne});
    }
}

int solve(vector<pair<int, int>> nums, int i, int m, int n)
{
    // Base Case
    if (i == nums.size())
        return 0;

    int zero = nums[i].first;
    int one = nums[i].second;
    int include = 0, exclude = 0;
    if (m - zero >= 0 and n - one >= 0)
        include = 1 + solve(nums, i + 1, m - zero, n - one);
    exclude = solve(nums, i + 1, m, n);

    return max(include, exclude);
}

int solveMem(vector<pair<int, int>> nums, int i, int m, int n, vector<vector<vector<int>>> &dp)
{
    // Base Case
    if (i == nums.size())
        return 0;

    if (dp[i][m][n] != -1)
        return dp[i][m][n];

    int zero = nums[i].first;
    int one = nums[i].second;
    int include = 0, exclude = 0;
    if (m - zero >= 0 and n - one >= 0)
        include = 1 + solveMem(nums, i + 1, m - zero, n - one, dp);
    exclude = solveMem(nums, i + 1, m, n, dp);

    dp[i][m][n] = max(include, exclude);
    return dp[i][m][n];
}

int solveTab(vector<pair<int, int>> nums, int m, int n)
{
    int N = nums.size();
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                int zero = nums[i].first;
                int one = nums[i].second;
                int include = 0, exclude = 0;
                if (j - zero >= 0 and k - one >= 0)
                    include = 1 + dp[i + 1][j - zero][k - one];
                exclude = dp[i + 1][j][k];

                dp[i][j][k] = max(include, exclude);
            }
        }
    }
    return dp[0][m][n];
}

int findMaxForm(vector<string> &strs, int m, int n)
{
    vector<pair<int, int>> nums; // {no. of zeroes,no. of ones}
    convert(strs, nums);

    // 1. Recursion
    // return solve(nums,0,m,n);

    // 2. Memoization
    // int N = nums.size();
    // vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
    // return solveMem(nums,0,m,n,dp);

    // 3. Tabulation
    return solveTab(nums, m, n);
}

int main()
{
    //

    return 0;
}