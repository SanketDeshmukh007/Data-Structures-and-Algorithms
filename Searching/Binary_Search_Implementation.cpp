#include<bits/stdc++.h>
using namespace std;

bool BinarySearch(int a[],int n,int target)
{
    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(a[mid] == target)
        return true;
        else if(target > a[mid])
        start = mid + 1;
        else
        end = mid - 1;
    }
    return false;
}

int main()
{
    int a[] = {10,20,30,40,50,60,70,80};
    if(BinarySearch(a,8,71))
    cout << "Found" << endl;
    else cout << "Not Found" << endl;

    return 0;
}