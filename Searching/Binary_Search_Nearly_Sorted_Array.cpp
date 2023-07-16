#include<bits/stdc++.h>
using namespace std;

int search(int a[],int n,int target)
{
    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(target == a[mid])
        return mid;
        else if(target == a[mid-1])
        return mid - 1;
        else if(target == a[mid+1])
        return mid + 1;

        if(target > a[mid])
        start = mid + 2;
        else
        end = mid - 2;
    }
    return -1;
}

int main()
{
    int arr[] = {10,3,40,20,50,80,70};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 80;
    int ans = search(arr,n,target);

    cout << "Found at : " << ans << endl;

    return 0;
}