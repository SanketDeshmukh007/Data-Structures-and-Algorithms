#include<bits/stdc++.h>
using namespace std;

void Merge(int nums[],int start,int end)
{
    int total_len = end - start + 1;
    int gap = (total_len)/2 + (total_len)%2;

    while(gap != 0)
    {
        int i = start, j = i + gap;

        while(j <= end)
        {
            if(nums[i] > nums[j])
            swap(nums[i],nums[j]);

            i++,j++;
        }

        if(gap == 1)
        gap = 0;
        else
        gap = (gap / 2) + (gap % 2);
    }
}

void mergeSort(int nums[],int start,int end)
{
    // Base Case
    if(start >= end)
    return;

    int mid = start + (end - start)/2;

    mergeSort(nums,start,mid);
    mergeSort(nums,mid+1,end);

    Merge(nums,start,end);
}

int main()
{
    int nums[] = {80,70,60,50,40,30,20,10};
    int n = sizeof(nums)/sizeof(nums[0]);
    int start = 0;
    int end = n - 1;
    mergeSort(nums,start,end);
    for(auto x : nums)
    cout << x << " ";

    return 0;
}