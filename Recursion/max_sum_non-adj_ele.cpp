#include<bits/stdc++.h>
using namespace std;

void maximumSum(int arr[],int i,int n,int sum,int& maxi)
{
    // 1. Base Case
    if(i >= n)
    {
        maxi = max(maxi,sum);
        return;
    }

    // exclude
    maximumSum(arr,i+1,n,sum,maxi);
    // include
    sum += arr[i];
    maximumSum(arr,i+2,n,sum,maxi);
}

int main()
{
    int arr[] = {2,1,4,9};
    int i = 0;
    int n = 4;
    int sum = 0;
    int maxi = INT_MIN;

    maximumSum(arr,i,n,sum,maxi);
    cout << maxi << endl;

    return 0;
}