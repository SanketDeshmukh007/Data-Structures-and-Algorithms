#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &nums, int n, int k, int mid)
{
    int count = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (sum + nums[i] <= mid)
            sum += nums[i];
        else
        {
            count++;

            if (count > k or nums[i] > mid)
                return false;

            sum = 0;
            sum += nums[i];
        }
    }
    return true;
}

int splitArray(vector<int> &nums, int k)
{

    int n = nums.size();

    int ans = -1;

    int start = *max_element(nums.begin(), nums.end());
    int end = accumulate(nums.begin(), nums.end(), 0);

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(nums, n, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    return ans;
}

int main()
{
    vector<int> arr = {7,2,5,10,8};
    int k = 2;

    cout << splitArray(arr,k) << endl;

    return 0;
}