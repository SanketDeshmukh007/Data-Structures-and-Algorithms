#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    sort(strs.begin(), strs.end());
    int n = strs.size();
    string first = strs[0];
    string last = strs[n - 1];
    int length = min(first.length(), last.length());
    for (int i = 0; i < length; i++)
    {
        if (first[i] != last[i])
            return ans;

        ans.push_back(first[i]);
    }
    return ans;
}

int main()
{
    vector<string> strs = {"flower","flow","flight"};
    string ans = longestCommonPrefix(strs);
    cout << ans << endl;

    return 0;
}