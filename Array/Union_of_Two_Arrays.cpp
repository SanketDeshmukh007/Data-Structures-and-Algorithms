#include<bits/stdc++.h>
using namespace std;

vector<int> Union(vector<int> a,vector<int> b)
{
    int n = a.size();
    int m = b.size();
    vector<int> ans;
    int i = 0, j = 0;

    while(i < n and j < m)
    {
        if(a[i] < b[j])
        {
            ans.push_back(a[i]);
            i++;
        }
        else if(a[i] == b[j])
        {
            ans.push_back(a[i]);
            ans.push_back(b[j]);
            i++;
            j++;
        }
        else
        {
            ans.push_back(b[j]);
            j++;
        }
    }

    while(i < n)
    {
        ans.push_back(a[i++]);
    }

    while(j < m)
    {
        ans.push_back(b[j++]);
    }
    return ans;
}

int main()
{
    vector<int> a = {2,4,6,8};
    vector<int> b = {1,3,4,7};
    vector<int> ans = Union(a,b);
    for(auto x : ans)
    cout << x << " ";

    return 0;
}