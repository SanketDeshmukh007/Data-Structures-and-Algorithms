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
int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<vector<int>> v;
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            temp.push_back(matrix[i][j] - '0');
        }
        v.push_back(temp);
    }

    int area = largestRectangleArea(v[0]);

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j])
                v[i][j] += v[i - 1][j];
            else
                v[i][j] = 0;
        }
        area = max(area, largestRectangleArea(v[i]));
    }
    return area;
}

int main()
{
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int result = maximalRectangle(matrix);
    cout << "Maximal Rectangle Area: " << result << endl;

    return 0;
}