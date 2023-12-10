#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &envelopes, int prev, int curr)
{
    if (curr == envelopes.size())
        return 0;

    int include = 0;
    if (prev == -1 or (envelopes[prev][0] < envelopes[curr][0] and envelopes[prev][1] < envelopes[curr][1]))
        include = 1 + solve(envelopes, curr, curr + 1);
    int exclude = 0 + solve(envelopes, prev, curr + 1);

    return max(include, exclude);
}

int solveMem(vector<vector<int>> &envelopes, int prev, int curr, vector<vector<int>> &dp)
{
    if (curr == envelopes.size())
        return 0;
    if (dp[prev + 1][curr] != -1)
        return dp[prev][curr];

    int include = 0;
    if (prev == -1 or (envelopes[prev][0] < envelopes[curr][0] and envelopes[prev][1] < envelopes[curr][1]))
        include = 1 + solveMem(envelopes, curr, curr + 1, dp);
    int exclude = 0 + solveMem(envelopes, prev, curr + 1, dp);

    return dp[prev + 1][curr] = max(include, exclude);
}

static bool compare(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];

    return a[0] < b[0];
}

int optimalBinarySearch(vector<vector<int>> &envelopes)
{
    if (envelopes.size() == 0)
        return 0;

    // Sort envelopes in increasing order widthwise
    // if width of two envelopes is equal then sort in decreasing order heightwise
    sort(envelopes.begin(), envelopes.end(), compare);

    vector<int> ans;
    ans.push_back(envelopes[0][1]);

    for (int i = 1; i < envelopes.size(); i++)
    {
        if (envelopes[i][1] > ans.back())
            ans.push_back(envelopes[i][1]);
        else
        {
            // overwrite the previous just big element
            int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
            ans[index] = envelopes[i][1];
        }
    }
    return ans.size();
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    // sort(envelopes.begin(),envelopes.end());
    // 1. Recursion
    // return solve(envelopes,-1,0);
    // 2. Memoization
    // int n = envelopes.size();
    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // return solveMem(envelopes,-1,0,dp);
    // 3. Optimal
    return optimalBinarySearch(envelopes);
}

int main()
{
    //

    return 0;
}