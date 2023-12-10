#include <bits/stdc++.h>
using namespace std;

bool solve(string &s1, string &s2, string &s3, int i, int j, int k)
{
    if (i == s1.length() and j == s2.length() and k == s3.length())
        return true;

    bool ans = false;

    if (i < s1.length() and s1[i] == s3[k])
        ans = ans or solve(s1, s2, s3, i + 1, j, k + 1);
    if (j < s2.length() and s2[j] == s3[k])
        ans = ans or solve(s1, s2, s3, i, j + 1, k + 1);

    return ans;
}

bool solveMem(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<vector<int>>> &dp)
{
    if (i == s1.length() and j == s2.length() and k == s3.length())
        return true;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    bool ans = false;

    if (i < s1.length() and s1[i] == s3[k])
        ans = ans or solveMem(s1, s2, s3, i + 1, j, k + 1, dp);
    if (j < s2.length() and s2[j] == s3[k])
        ans = ans or solveMem(s1, s2, s3, i, j + 1, k + 1, dp);

    return dp[i][j][k] = ans;
}

bool solveTab(string &s1, string &s2, string &s3)
{
    vector<vector<vector<int>>> dp(s1.length() + 1, vector<vector<int>>(s2.length() + 1, vector<int>(s3.length() + 1, 0)));
    dp[s1.size()][s2.size()][s3.size()] = 1;

    for (int i = s1.length(); i >= 0; i--)
    {
        for (int j = s2.length(); j >= 0; j--)
        {
            for (int k = s3.length(); k >= 0; k--)
            {
                if (i == s1.length() and j == s2.length() and k == s3.length())
                    continue;
                bool ans = false;

                if (i < s1.length() and s1[i] == s3[k])
                    ans = ans or dp[i + 1][j][k + 1];
                if (j < s2.length() and s2[j] == s3[k])
                    ans = ans or dp[i][j + 1][k + 1];

                dp[i][j][k] = ans;
            }
        }
    }
    return dp[0][0][0];
}

bool isInterleave(string s1, string s2, string s3)
{
    // 1. Recursion
    // return solve(s1,s2,s3,0,0,0);
    // 2. Memoization
    // vector<vector<vector<int>>> dp(s1.length()+1,vector<vector<int>>(s2.length()+1,vector<int>(s3.length()+1,-1)));
    // return solveMem(s1,s2,s3,0,0,0,dp);
    // 3. Tabulation
    return solveTab(s1, s2, s3);
}

int main()
{
    //

    return 0;
}