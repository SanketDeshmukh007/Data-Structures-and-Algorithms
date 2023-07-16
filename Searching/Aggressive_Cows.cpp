#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> a,int n,int k,int mid)
{
    int cowCount = 1;
    int pos = a[0];

    for(int i = 1;i < n; i++)
    {
        if(a[i] - pos >= mid)
        {
            cowCount++;

            if(cowCount == k)
            return true;

            pos = a[i];
        }
    }
    return false;
}

int findDistance(vector<int> a,int n,int k)
{
    sort(a.begin(),a.end());
    
    int ans = -1;
    int start = 0;
    int end = a[n-1] - a[0];

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(isPossible(a,n,k,mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        end = mid - 1;
    }
    return ans;
}

int main()
{
    vector<int> stalls = {1,2,4,8,9};
    int n = 5;
    int k = 3;

    cout << findDistance(stalls,n,k) << endl;

    return 0;
}