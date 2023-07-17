#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& nums,int start,int end)
{
    // 1. Base Case
    if(end == int(nums.size()))
    return;

    // 2. Processing
    for(int i = start; i <= end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    // 3. Recursive Relation
    print(nums,start,end+1);
}

void printsubarray(vector<int>& nums)
{
    for(int start = 0; start < int(nums.size()); start++)
    {
        print(nums,start,start);
    }
}

int main()
{
    vector<int> nums = {1,2,3,4,5};
    printsubarray(nums);

    return 0;
}