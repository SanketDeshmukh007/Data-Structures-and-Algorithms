#include <bits/stdc++.h>
using namespace std;

void robbery(vector<int> &nums, int i, int sum, int &maxi)
{
    // 1. Base Case
    if (i >= int(nums.size()))
    {
        maxi = max(sum, maxi);
        return;
    }

    // Exclude
    robbery(nums, i + 1, sum, maxi);
    // Include
    robbery(nums, i + 2, sum + nums[i], maxi);
}

int rob(vector<int> &nums)
{
    int i = 0;
    int sum = 0;
    int maxi = INT_MIN;
    robbery(nums, i, sum, maxi);
    return maxi;
}

int main()
{
    vector<int> nums = {2,7,9,3,1};

    cout << rob(nums) << endl;

    return 0;
}