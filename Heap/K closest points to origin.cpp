#include <bits/stdc++.h>
using namespace std;

static bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> ans;

    vector<pair<int, int>> temp;
    int i = 0;
    for (auto x : points)
    {
        pair<int, int> p;
        p.first = i++;
        p.second = x[0] * x[0] + x[1] * x[1];
        temp.push_back(p);
    }

    sort(temp.begin(), temp.end(), compare);
    i = 0;
    while (k--)
    {
        ans.push_back(points[temp[i++].first]);
    }
    return ans;
}

int main()
{
    vector<vector<int>> points = {{1,3},{-2,2}};
    int k = 1;
    vector<vector<int>> ans = kClosest(points,k);

    for(auto x : ans)
    {
        for(auto y : x)
        cout << y << " ";
        
        cout << endl;
    }

    return 0;
}