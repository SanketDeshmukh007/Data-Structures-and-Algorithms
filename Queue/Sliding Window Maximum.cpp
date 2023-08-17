#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> ans;
    deque<int> q;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        // Remove elements which are out of window
        if (!q.empty() and (i - q.front() >= k))
            q.pop_front();

        // Remove previous smaller elements from deque
        while (!q.empty() and nums[i] > nums[q.back()])
            q.pop_back();

        q.push_back(i);

        // note the ans for index i = 2 and above
        // for i = 2 -- 1 window completes
        if (i >= k - 1)
            ans.push_back(nums[q.front()]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums,k);
    for(auto x : ans)
    cout << x << " ";

    return 0;
}