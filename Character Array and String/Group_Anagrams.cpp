#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> m;

    for (auto x : strs)
    {
        string word = x;
        sort(word.begin(), word.end());
        m[word].push_back(x);
    }

    vector<vector<string>> ans;
    for (auto x : m)
        ans.push_back(x.second);

    return ans;
}

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}