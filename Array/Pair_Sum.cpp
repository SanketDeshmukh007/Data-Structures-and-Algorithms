#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> pairSum(vector<int> a,vector<int> b,int sum)
{
    vector<pair<int,int>> p;
    int m = a.size();
    int n = b.size();
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i] + b[j] == sum)
            {
                p.push_back({a[i],b[j]});
            }
        }
    }
    return p;
}

int main()
{
    vector<int> a = {1,3,5,7};
    vector<int> b = {2,4,6};
    int sum = 9;
    vector<pair<int,int>> ans = pairSum(a,b,sum);
    for(auto x : ans)
    cout << x.first << " " << x.second << endl;

    return 0;
}