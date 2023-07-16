#include<bits/stdc++.h>
using namespace std;

int oddOccuringElement(int a[],int n)
{
    int start = 0;
    int end = n - 1;

    while(start < end)
    {
        int mid = start + (end - start)/2;

        if(mid % 2 == 0)
        {
            if(a[mid] == a[mid+1])
            start = mid + 1;
            else
            end = mid;
        }
        else
        {
            if(a[mid] == a[mid-1])
            start = mid + 1;
            else
            end = mid - 1;
        }
    }
    return a[start];
}

int main()
{
    int arr[] = {1,1,2,2,3,3,4,4,3,600,600,4,4};
    int n = sizeof(arr)/sizeof(int);

    cout << "Odd occuring element is: " << oddOccuringElement(arr,n) << endl;

    return 0;
}