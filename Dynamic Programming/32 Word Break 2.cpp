#include <bits/stdc++.h>
using namespace std;

vector<string> solve(string s, unordered_map<string, bool> &dict, int start)
{
    if (start == s.length())
        return {""};

    vector<string> ans;

    string word = "";
    for (int i = start; i < s.length(); i++)
    {
        word += s[i];

        if (dict.find(word) == dict.end())
            continue;

        auto right = solve(s, dict, i + 1);

        for (auto x : right)
        {
            string endPart;
            if (x.length() > 0)
                endPart = " " + x;
            ans.push_back(word + endPart);
        }
    }
    return ans;
}

unordered_map<int, vector<string>> dp;
vector<string> solveMem(string s, unordered_map<string, bool> &dict, int start)
{
    if (start == s.length())
        return {""};

    if (dp.find(start) != dp.end())
        return dp[start];

    vector<string> ans;

    string word = "";
    for (int i = start; i < s.length(); i++)
    {
        word += s[i];

        if (dict.find(word) == dict.end())
            continue;

        auto right = solveMem(s, dict, i + 1);

        for (auto x : right)
        {
            string endPart;
            if (x.length() > 0)
                endPart = " " + x;
            ans.push_back(word + endPart);
        }
    }
    return dp[start] = ans;
}

vector<string> wordBreak(string s, vector<string> &wordDict)
{
    unordered_map<string, bool> dict;
    for (auto x : wordDict)
        dict[x] = true;

    // 1. Recursion
    // return solve(s,dict,0);

    // 2. Memoization
    return solveMem(s, dict, 0);
}

int main()
{
    //

    return 0;
}