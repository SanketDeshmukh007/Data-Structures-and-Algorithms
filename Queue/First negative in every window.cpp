#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegative(vector<int> arr, int n, int k)
{
    vector<int> ans;
    queue<int> q;

    // Process for first window
    for (int i = 0; i < k; i++)
    {
        // store index so we can find that it comes in window or not
        if (arr[i] < 0)
            q.push(i);
    }

    // for remaining windows
    for (int i = k; i < n; i++)
    {
        // first window ans
        if (q.empty())
            ans.push_back(0);
        else
            ans.push_back(arr[q.front()]);

        // remove out of window elements
        if (!q.empty() and (i - q.front() >= k))
        {
            q.pop();
        }

        if (arr[i] < 0)
            q.push(i);
    }
    // last window ans
    if (q.empty())
        ans.push_back(0);
    else
        ans.push_back(arr[q.front()]);

    return ans;
}

int main()
{
    vector<int> arr = {12,-1,-7,8,-15,30,16,28};
    int n = arr.size();
    int k = 3;
    vector<int> ans = firstNegative(arr,n,k);
    for(auto x : ans)
    cout << x << " ";

    return 0;
}