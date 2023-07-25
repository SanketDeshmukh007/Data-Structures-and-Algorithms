#include <bits/stdc++.h>
using namespace std;

void permutations(vector<int> nums, int i, vector<vector<int>> &ans)
{
    if (i == int(nums.size()))
    {
        ans.push_back(nums);
        return;
    }

    for (int j = i; j < int(nums.size()); j++)
    {
        swap(nums[i], nums[j]);

        permutations(nums, i + 1, ans);

        swap(nums[i], nums[j]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{

    vector<vector<int>> ans;
    int i = 0;
    permutations(nums, i, ans);

    return ans;
}

int main()
{
    vector<int> nums = {1,2,3};

    vector<vector<int>> ans = permute(nums);

    for(int i = 0; i < int(ans.size()); i++)
    {
        for(int j = 0; j < int(ans[0].size()); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}