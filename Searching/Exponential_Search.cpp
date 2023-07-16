#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr,int start,int end,int target)
{
    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(target == arr[mid])
        return mid;
        else if(target > arr[mid])
        start = mid + 1;
        else
        end = mid - 1;
    }
    return -1;
}

int ExponentialSearch(vector<int>& arr,int target)
{
    if(target == arr[0])
    return 0;

    int i = 1;
    int n = arr.size();
    while(i < n and arr[i] <= target)
    {
        i = i * 2;
    }

    return search(arr,i/2,min(i,n-1),target);
}

int main()
{
    vector<int> arr = {3,4,5,6,11,13,54,55,56,70};
    int target = 13;

    cout << ExponentialSearch(arr,target) << endl;

    return 0;
}