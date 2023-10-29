#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.second < b.second;
}

int solve(int n,vector<int>& arr,vector<int>& dep)
{
    vector<pair<int,int>> v;

    for(int i = 0; i < n; i++)
    {
        v.push_back({arr[i],dep[i]});
    }

    sort(v.begin(),v.end(),cmp);

    int cnt = 1;
    int lastdep = v[0].second;
    cout << v[0].first << " " << v[0].second << endl;

    for(int i = 1; i < n; i++)
    {
        if(v[i].first >= lastdep)
        {
            cnt++;
            cout << v[i].first << " " << v[i].second << endl;
            lastdep = v[i].second;
        }
    }
    return cnt;
}

int main()
{
    int n = 4;
    vector<int> arr = {5,8,2,4};
    vector<int> dep = {7,11,6,5};

    int ans = solve(n,arr,dep);
    cout << "Answer is " << ans << endl;

    return 0;
}