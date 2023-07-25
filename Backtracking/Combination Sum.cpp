#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> v, int index)
{
    // Base Case
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }
    if (target < 0)
        return;

    for (int i = index; i < int(candidates.size()); i++)
    {
        v.push_back(candidates[i]);
        solve(candidates, target - candidates[i], ans, v, i);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> v;
    int index = 0;
    solve(candidates, target, ans, v, index);
    return ans;
}

int main()
{
    vector<int> candidates = {2,3,6,7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(candidates,target);

    for(auto &x : ans)
    {
        for(auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}