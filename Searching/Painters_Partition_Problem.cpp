#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> a,int m,int n,int mid)
{
    int paintercount = 1;
    int boardsum = 0;

    for(int i = 0; i < n; i++)
    {
        if(boardsum + a[i] <= mid)
        boardsum += a[i];
        else
        {
            paintercount++;

            if(paintercount > m or a[i] > mid)
            return false;
            
            boardsum = 0;
            boardsum += a[i];
        }
    }
    return true;
}

int findTime(vector<int> a,int m,int n)
{
    int ans = -1;

    int start = *max_element(a.begin(),a.end());
    int end = accumulate(a.begin(),a.end(),0);

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(isPossible(a,m,n,mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        start = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int m = 2;
    int n = 4;

    cout << findTime(arr,m,n) << endl; 

    return 0;
}