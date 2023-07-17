#include<bits/stdc++.h>
using namespace std;

bool BinarySearch(int arr[],int start,int end,int target)
{
    // 1. Base Case
    if(start > end)
    return false;

    // 2. Processing
    int mid = start + (end - start)/2;
    if(arr[mid] == target)
    return true;

    // 3. Recursive Relation
    if(target > arr[mid])
    return BinarySearch(arr,mid+1,end,target);
    else
    return BinarySearch(arr,start,mid-1,target);
}

int main()
{
    int arr[] = {10,20,30,40,50,60,70};
    int n = sizeof(arr)/sizeof(int);
    int start = 0;
    int end = n -1;
    int target = 15;

    if(BinarySearch(arr,start,end,target))
    cout << "Found" << endl;
    else
    cout << "Not Found" << endl;

    return 0;
}