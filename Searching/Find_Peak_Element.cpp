#include<bits/stdc++.h>
using namespace std;

int recursiveBinarySearch(vector<int>& nums,int start,int end)
{
    if(start == end)
    return nums[start];

    int mid = start + (end - start)/2;

    if(nums[mid] > nums[mid+1])
    return recursiveBinarySearch(nums,start,mid);
    else
    return recursiveBinarySearch(nums,mid+1,end);
}

int findpeakelement(vector<int>& nums)
{
    int start = 0;
    int end = nums.size() - 1;
    return recursiveBinarySearch(nums,start,end);
}

int main()
{
    vector<int> nums = {1,2,1,3,4,6,4};
    cout << findpeakelement(nums) << endl;

    return 0;
}