#include <bits/stdc++.h>
using namespace std;

vector<int> previousSmallerElement(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];

        while (s.top() != -1 and arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }
    return ans;
}

vector<int> nextSmallerElement(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (s.top() != -1 and arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int> prev = previousSmallerElement(heights);

    vector<int> next = nextSmallerElement(heights);

    int n = heights.size();
    vector<int> area(n);
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (next[i] == -1)
            next[i] = n;

        area[i] = heights[i] * (next[i] - prev[i] - 1);
        maxi = max(maxi, area[i]);
    }

    return maxi;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << endl;

    return 0;
}