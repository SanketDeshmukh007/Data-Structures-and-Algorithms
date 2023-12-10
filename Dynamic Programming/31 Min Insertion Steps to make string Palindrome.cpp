#include <bits/stdc++.h>
using namespace std;

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

int longestPalindromeSubseq(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    int ans = longestCommonSubsequenceTab(s, rev);
    return ans;
}

int minInsertions(string s)
{
    int ans = longestPalindromeSubseq(s);
    return (s.length() - ans);
}

int main()
{
    //

    return 0;
}