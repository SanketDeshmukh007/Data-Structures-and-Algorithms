#include<bits/stdc++.h>
using namespace std;

int minimumCoins(int arr[],int n,int target)
{
    // 1. Base Case
    if(target == 0)
    return 0;
    else if(target < 0)
    return INT_MAX;

    // 2. Recursive relation and process
    int minCoins = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        int ans = minimumCoins(arr,n,target-arr[i]);
        if(ans != INT_MAX)
        minCoins = min(minCoins,ans+1);
    }

    return minCoins;
}

int main()
{
    int arr[] = {1,2,3};
    int n = 3;
    int target = 5;
    int ans = minimumCoins(arr,n,target);
    cout << ans << endl;

    return 0;
}