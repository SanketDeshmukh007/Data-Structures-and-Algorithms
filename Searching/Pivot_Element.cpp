#include<bits/stdc++.h>
using namespace std;

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
        return mid - 1;

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
    int pivotElement = pivot(arr,n);

    cout << arr[pivotElement] << endl;

    return 0;
}