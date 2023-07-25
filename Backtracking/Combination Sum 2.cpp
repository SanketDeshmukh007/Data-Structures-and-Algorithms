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
        if (i > index and candidates[i] == candidates[i - 1])
            continue;

        v.push_back(candidates[i]);
        solve(candidates, target - candidates[i], ans, v, i + 1);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> v;
    int index = 0;
    solve(candidates, target, ans, v, index);
    return ans;
}


int main()
{
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> ans = combinationSum2(candidates,target);

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