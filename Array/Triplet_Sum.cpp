#include<bits/stdc++.h>
using namespace std;

vector<int> TripletSum(vector<int> a,int target)
{
    vector<int> ans;
    int n = a.size();

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                if(a[i] + a[j] + a[k] == target)
                {
                    ans.push_back(a[i]);
                    ans.push_back(a[j]);
                    ans.push_back(a[k]);
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> a = {10,20,30,40};
    
    vector<int> ans = TripletSum(a,80);

    for(auto x : ans)
    cout << x << " ";

    return 0;
}