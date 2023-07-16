#include<bits/stdc++.h>
using namespace std;

bool search(int a[],int n,int target)
{
    int start = 0;
    int end = n -1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(a[mid] == target)
        return true;
        if(a[start] == a[mid] and a[mid] == a[end])
        {
            start++;
            end--;
        }
        else if(a[start] <= a[mid])
        {
            if(target >= a[start] and target < a[mid])
            end = mid - 1;
            else start = mid + 1;
        }
        else if(a[mid] <= a[end])
        {
            if(target > a[mid] and target <= a[end])
            start = mid + 1;
            else end = mid - 1;
        }
    }
    return false;
}

int main()
{
    int arr[] = {3,1,2,3,3,3,3};
    int n = 7;
    int target = 5;
    if(search(arr,n,target))
    cout << "Present" << endl;
    else cout << "Not Present" << endl;

    return 0;
}