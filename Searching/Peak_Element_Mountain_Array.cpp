#include<bits/stdc++.h>
using namespace std;

int PeakElement(int arr[],int start,int end)
{
    while(start < end)
    {
        int mid = start + (end - start)/2;

        if(arr[mid] < arr[mid+1])
        start = mid + 1;
        else
        end = mid;
    }
    return arr[start];
}

int main()
{
    int arr[] = {0,10,5,2};
    int start = 0;
    int end = 3;

    cout << PeakElement(arr,start,end) << endl;

    return 0;
}