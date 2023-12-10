#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &satisfaction, int i, int time)
{
    if (i == satisfaction.size())
        return 0;

    int includeLikeTimeCoeff = time * satisfaction[i] + solve(satisfaction, i + 1, time + 1);
    int excludeLikeTimeCoeff = 0 + solve(satisfaction, i + 1, time);

    return max(includeLikeTimeCoeff, excludeLikeTimeCoeff);
}

int solveMem(vector<int> &satisfaction, int i, int time, vector<vector<int>> &dp)
{
    if (i == satisfaction.size())
        return 0;
    if (dp[i][time] != -1)
        return dp[i][time];

    int includeLikeTimeCoeff = time * satisfaction[i] + solveMem(satisfaction, i + 1, time + 1, dp);
    int excludeLikeTimeCoeff = 0 + solveMem(satisfaction, i + 1, time, dp);

    return dp[i][time] = max(includeLikeTimeCoeff, excludeLikeTimeCoeff);
}

int solveTab(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int time = n; time >= 1; time--)
        {
            int includeLikeTimeCoeff = time * satisfaction[i] + dp[i + 1][time + 1];
            int excludeLikeTimeCoeff = 0 + dp[i + 1][time];

            dp[i][time] = max(includeLikeTimeCoeff, excludeLikeTimeCoeff);
        }
    }

    return dp[0][1];
}

int maxSatisfaction(vector<int> &satisfaction)
{
    sort(satisfaction.begin(), satisfaction.end());

    // 1. Recursion
    // return solve(satisfaction,0,1);

    // 2. Memoization
    // int n = satisfaction.size();
    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // return solveMem(satisfaction,0,1,dp);

    // 3. Tabulation
    return solveTab(satisfaction);
}

int main()
{
    //

    return 0;
}