#include<bits/stdc++.h>
using namespace std;

pair<int,int> TwoSum(vector<int> a,int target)
{
    pair<int,int> ans;

    for(int i = 0; i < int(a.size()); i++)
    {
        for(int j = i+1; j < int(a.size()); j++)
        {
            if(a[i] + a[j] == target)
            {
                ans.first = a[i];
                ans.second = a[j];
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> a = {2,7,11,15};
    int target = 9;
    pair<int,int> p = TwoSum(a,target);
    
    cout << p.first << " " << p.second << endl;

    return 0;
}