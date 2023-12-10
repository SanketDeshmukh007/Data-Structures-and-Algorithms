#include <bits/stdc++.h>
using namespace std;

int optimalBinarySearch(vector<int> &nums, vector<int> &LIS)
{
    if (nums.size() == 0)
        return 0;

    vector<int> ans;
    ans.push_back(nums[0]);
    LIS.push_back(1);

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
            LIS.push_back(ans.size());
        }
        else
        {
            // overwrite the previous just big element
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[index] = nums[i];
            LIS.push_back(index + 1);
        }
    }
    return ans.size();
}

int minimumMountainRemovals(vector<int> &nums)
{
    vector<int> LIS, LDS;
    // Make LIS and LDS array by taking each element as pivot
    optimalBinarySearch(nums, LIS);
    reverse(nums.begin(), nums.end());
    optimalBinarySearch(nums, LDS);
    reverse(LDS.begin(), LDS.end());

    vector<int> maxSize(nums.size(), -1);
    int maxi = INT_MIN;
    for (int i = 0; i < LIS.size(); i++)
    {
        if (LIS[i] == 1 or LDS[i] == 1)
            continue;

        maxSize[i] = LIS[i] + LDS[i] - 1;
        maxi = max(maxi, maxSize[i]);
    }
    return nums.size() - maxi;
}

int main()
{
    //

    return 0;
}