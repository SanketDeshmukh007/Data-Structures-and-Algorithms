#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &ans, string output, int open, int close)
{
    // Base case
    if (open == 0 and close == 0)
    {
        ans.push_back(output);
        return;
    }

    // Open
    if (open > 0)
    {
        output.push_back('(');
        solve(ans, output, open - 1, close);
        output.pop_back();
    }

    if (close > open)
    {
        output.push_back(')');
        solve(ans, output, open, close - 1);
        output.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string output = "";
    int open = n;
    int close = n;
    solve(ans, output, open, close);
    return ans;
}

int main()
{
    vector<string> ans = generateParenthesis(3);
    for(auto x : ans)
    cout << x << endl;

    return 0;
}