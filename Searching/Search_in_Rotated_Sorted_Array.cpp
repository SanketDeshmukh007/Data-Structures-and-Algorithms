#include<bits/stdc++.h>
using namespace std;

int search(int a[],int start,int end,int target)
{
    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(a[mid] == target)
        return mid;
        else if(target > a[mid])
        start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int pivot(int a[],int n)
{
    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(a[mid] > a[mid+1])
        return mid;
        else if(a[mid-1] > a[mid])
        return mid-1;

        if(a[start] > a[mid])
        end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {9,10,2,4,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 4;
    int Pivot = pivot(arr,n);
    int ans;

    if(target >= arr[0] and target <= arr[Pivot])
    ans = search(arr,0,Pivot,target);
    else
    ans = search(arr,Pivot+1,n-1,target);

    cout << "Found at : " << ans << endl;

    return 0;
}