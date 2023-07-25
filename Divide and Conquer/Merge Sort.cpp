#include<bits/stdc++.h>
using namespace std;

void merge(int *nums,int start,int end)
{
    int mid = start + (end - start)/2;

    int n1 = mid - start + 1;
    int n2 = end - mid;
    int *a = new int[n1];
    int *b = new int[n2];

    for(int i = 0; i < n1; i++)
    {
        a[i] = nums[start + i];
    }
    for(int i = 0; i < n2; i++)
    {
        b[i] = nums[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;
    while(i < n1 and j < n2)
    {
        if(a[i] < b[j])
        {
            nums[k] = a[i];
            i++,k++;
        }
        else
        {
            nums[k] = b[j];
            k++,j++;
        }
    }
    while(i < n1)
    {
        nums[k] = a[i];
        i++,k++;
    }
    while(j < n2)
    {
        nums[k] = b[j];
        j++,k++;
    }
}

void mergeSort(int *nums,int start,int end)
{
    // Base Case
    // 1. if start == end i.e 1 element already sorted
    // 2. if start > end i.e out of scope
    if(start >= end)
    return;

    int mid = start + (end - start)/2;

    mergeSort(nums,start,mid);

    mergeSort(nums,mid+1,end);

    merge(nums,start,end);
}

int main()
{
    int nums[] = {5,2,3,1,2,3,4};
    int n = sizeof(nums)/sizeof(nums[0]);
    int start = 0;
    int end = n - 1;
    mergeSort(nums,start,end);
    for(auto x : nums)
    cout << x << " ";

    return 0;
}