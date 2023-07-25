#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    int maxi = nums[0];

    for (int i = 0; i < n; i++)
    {
        sum = sum + nums[i];
        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout <<maxSubArray(nums) << endl;

    return 0;
}