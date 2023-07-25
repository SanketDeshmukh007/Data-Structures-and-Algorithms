#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, vector<vector<int>> &ans, int i)
{
    if (i >= int(nums.size()))
    {
        ans.push_back(nums);
        return;
    }

    unordered_map<int, bool> visited;
    for (int j = i; j < int(nums.size()); j++)
    {
        if (visited.find(nums[j]) != visited.end())
            continue;

        visited[nums[j]] = true;
        swap(nums[i], nums[j]);
        solve(nums, ans, i + 1);
        swap(nums[i], nums[j]);
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> ans;
    int i = 0;
    solve(nums, ans, i);
    // set<vector<int>> s;
    // for (auto x : ans)
    //     s.insert(x);
    // ans.clear();
    // for (auto x : s)
    //     ans.push_back(x);
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 2};

    vector<vector<int>> ans = permuteUnique(nums);

    for (int i = 0; i < int(ans.size()); i++)
    {
        for (int j = 0; j < int(ans[0].size()); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}