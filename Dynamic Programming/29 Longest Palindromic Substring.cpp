#include <bits/stdc++.h>
using namespace std;

int maxLen = 1, start = 0;
bool checkPalindrome(string s, int i, int j)
{
    if (i >= j)
    {
        return true;
    }

    bool ans = false;
    if (s[i] == s[j])
        ans = checkPalindrome(s, i + 1, j - 1);

    if (ans)
    {
        int currLen = j - i + 1;
        if (maxLen < currLen)
        {
            maxLen = currLen;
            start = i;
        }
    }
    return ans;
}

bool checkPalindromeMem(string s, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j)
    {
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    bool ans = false;
    if (s[i] == s[j])
        ans = checkPalindromeMem(s, i + 1, j - 1, dp);

    if (ans)
    {
        int currLen = j - i + 1;
        if (maxLen < currLen)
        {
            maxLen = currLen;
            start = i;
        }
    }

    dp[i][j] = ans;
    return dp[i][j];
}

string longestPalindrome(string s)
{
    int n = s.length();

    // Memoization
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool temp = checkPalindromeMem(s, i, j, dp);
        }
    }

    return s.substr(start, maxLen);
}

int main()
{
    //

    return 0;
}