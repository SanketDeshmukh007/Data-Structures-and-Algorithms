#include <bits/stdc++.h>
using namespace std;

vector<int> Maximum(vector<int> nums, int n, int k)
{
    vector<int> ans;
    deque<int> q;

    for (int i = 0; i < n; i++)
    {
        while (!q.empty() and (i - q.front() >= k))
        {
            q.pop_front();
        }

        while (!q.empty() and nums[i] > nums[q.back()])
        {
            q.pop_back();
        }

        q.push_back(i);

        if (i >= k - 1)
            ans.push_back(nums[q.front()]);
    }
    return ans;
}

vector<int> Minimum(vector<int> nums, int n, int k)
{
    vector<int> ans;
    deque<int> q;

    for (int i = 0; i < n; i++)
    {
        while (!q.empty() and (i - q.front() >= k))
        {
            q.pop_front();
        }

        while (!q.empty() and nums[i] < nums[q.back()])
        {
            q.pop_back();
        }

        q.push_back(i);

        if (i >= k - 1)
            ans.push_back(nums[q.front()]);
    }
    return ans;
}

long long sumOfMaxAndMin(vector<int> &nums, int n, int k)
{
    vector<int> maxi = Maximum(nums, n, k);
    vector<int> mini = Minimum(nums, n, k);

    int N = maxi.size();
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += maxi[i] + mini[i];
    }
    
    return sum;
}

int main()
{
    vector<int> nums = {2,5,-1,7,-3,-1,-2};
    cout << sumOfMaxAndMin(nums,nums.size(),4) << endl;
}
