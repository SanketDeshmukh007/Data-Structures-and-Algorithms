#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequenceRec(string a, string b, int i, int j)
{
    if (i == a.length() or j == b.length())
        return 0;

    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 1 + longestCommonSubsequenceRec(a, b, i + 1, j + 1);
    }
    else
    {
        ans = 0 + max(longestCommonSubsequenceRec(a, b, i, j + 1), longestCommonSubsequenceRec(a, b, i + 1, j));
    }

    return ans;
}

// TC - O(N*M) and SC - O(N*M)
int longestCommonSubsequenceMem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    if (i == a.length() or j == b.length())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 1 + longestCommonSubsequenceMem(a, b, i + 1, j + 1, dp);
    }
    else
    {
        ans = 0 + max(longestCommonSubsequenceMem(a, b, i, j + 1, dp), longestCommonSubsequenceMem(a, b, i + 1, j, dp));
    }

    dp[i][j] = ans;
    return dp[i][j];
}

int longestCommonSubsequenceTab(string a, string b)
{
    int n = max(a.length(), b.length());
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length(); j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            else
            {
                ans = 0 + max(dp[i][j + 1], dp[i + 1][j]);
            }

            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int longestCommonSubsequence(string text1, string text2)
{
    // 1. Recursion
    // return longestCommonSubsequenceRec(text1,text2,0,0);

    // 2. Top Down Approach
    // int n = max(text1.length(),text2.length());
    // vector<vector<int>> dp(n,vector<int>(n,-1));
    // return longestCommonSubsequenceMem(text1,text2,0,0,dp);

    // 3. Bottom Up Approach
    return longestCommonSubsequenceTab(text1, text2);
}

int longestPalindromeSubseq(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    int ans = longestCommonSubsequence(s, rev);
    return ans;
}

int main()
{
    //

    return 0;
}