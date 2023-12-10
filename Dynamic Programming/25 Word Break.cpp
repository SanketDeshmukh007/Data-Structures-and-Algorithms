#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
bool valid(string word, vector<string> &wordDict)
{
    for (auto x : wordDict)
    {
        if (x == word)
            return true;
    }
    return false;
}

bool solve(string s, vector<string> &wordDict, int start)
{
    if (start == s.length())
        return true;

    bool ans = false;
    string word = "";
    for (int i = start; i < s.length(); i++)
    {
        word += s[i];
        if (valid(word, wordDict))
        {
            ans = ans or solve(s, wordDict, i + 1);
        }
    }
    return ans;
}

bool solveMem(string s, vector<string> &wordDict, int start, vector<int> &dp)
{
    if (start == s.length())
        return true;
    if (dp[start] != -1)
        return dp[start];

    bool ans = false;
    string word = "";
    for (int i = start; i < s.length(); i++)
    {
        word += s[i];
        if (valid(word, wordDict))
        {
            ans = ans or solveMem(s, wordDict, i + 1, dp);
        }
    }
    dp[start] = ans;
    return dp[start];
}

bool solveTab(string s, vector<string> &wordDict)
{
    int n = s.length();
    vector<bool> dp(n + 1, true);

    for (int start = n - 1; start >= 0; start--)
    {
        bool ans = false;
        string word = "";
        for (int i = start; i < s.length(); i++)
        {
            word += s[i];
            if (valid(word, wordDict))
            {
                ans = ans or dp[i + 1];
            }
        }
        dp[start] = ans;
    }
    return dp[0];
}

bool wordBreak(string s, vector<string> &wordDict)
{
    // 1. Recursion
    // return solve(s,wordDict,0);

    // 2. Memoization
    // int n = s.length();
    // vector<int> dp(n+1,-1);
    // return solveMem(s,wordDict,0,dp);

    // 3. Tabulation
    return solveTab(s, wordDict);
}

int main()
{
    //

    return 0;
}