#include<bits/stdc++.h>
using namespace std;

int findPairs2(vector<int>& nums, int k)
{
    set<pair<int,int>> s;
    sort(nums.begin(),nums.end());

    for(int i = 0; i < nums.size(); i++)
    {
        int curr = nums[i];
        int target = nums[i] + k;
        if(binary_search(nums.begin(),nums.end(),target))
        {
            s.insert({curr,target});
        }
    }  
    return s.size();  
}

int findPairs(vector<int>& nums, int k)
{
    set<pair<int,int>> s;
    sort(nums.begin(),nums.end());

    int i = 0, j = 1;
    while(j < nums.size())
    {
        int diff = nums[j] - nums[i];
        if(diff == k)
        {
            s.insert({nums[i],nums[j]});
            i++;
            j++;
        }
        else if(diff > k)
        i++;
        else 
        j++;
        
        if(i == j)
        j++;
    }  
    return s.size();  
}

int main()
{
    vector<int> nums = {3,1,4,1,5};
    int k = 2;
    int ans = findPairs(nums,k);
    cout << ans << endl;

    return 0;
}