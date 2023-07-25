#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &ans, string output, int index, string digits, vector<string> m)
{
    // Base Case
    if (index >= int(digits.length()))
    {
        ans.push_back(output);
        return;
    }

    int digit = digits[index] - '0';
    string value = m[digit];
    for (int i = 0; i < int(value.length()); i++)
    {
        output.push_back(value[i]);
        solve(ans, output, index + 1, digits, m);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.length() == 0)
        return ans;

    string output = "";
    int index = 0;
    vector<string> m(10);
    m[2] = "abc";
    m[3] = "def";
    m[4] = "ghi";
    m[5] = "jkl";
    m[6] = "mno";
    m[7] = "pqrs";
    m[8] = "tuv";
    m[9] = "wxyz";
    solve(ans, output, index, digits, m);
    return ans;
}

int main()
{
    vector<string> ans = letterCombinations("23");
    for(auto x : ans)
    cout << x << endl;

    return 0;
}