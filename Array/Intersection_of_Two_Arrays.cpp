#include<bits/stdc++.h>
using namespace std;

vector<int> Intersection(vector<int> a,vector<int> b)
{
    vector<int> ans;
    int m = a.size();
    int n = b.size();
    int i = 0, j = 0;

    while (i < m and j < n)
    {
        if(a[i] < b[j])
        {
            i++;
        }
        else if(a[i] > b[j])
        {
            j++;
        }
        else if(a[i] == b[j])
        {
            ans.push_back(a[i]);
            i++,j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> a = {1,2,3,4,6,8};
    vector<int> b = {3,4,9,10};
    vector<int> ans = Intersection(a,b);
    for(auto x : ans)
    cout << x << " ";

    return 0;
}