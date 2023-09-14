#include <bits/stdc++.h>
using namespace std;

#define a ios_base::sync_with_stdio(false)
#define b cin.tie(0)
#define c cout.tie(0)

int findKthLargest(vector<int> &nums, int k)
{
    a;
    b;
    c;
    priority_queue<int, vector<int>, greater<int>> p;
    int n = nums.size();
    for (int i = 0; i < k; i++)
    {
        p.push(nums[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (nums[i] > p.top())
        {
            p.pop();
            p.push(nums[i]);
        }
    }
    return p.top();
}

int main()
{
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    cout << findKthLargest(arr,3) << endl;

    return 0;
}