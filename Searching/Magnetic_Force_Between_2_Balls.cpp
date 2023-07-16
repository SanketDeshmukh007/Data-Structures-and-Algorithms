#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> a,int n,int m,int mid)
{
    int ballcount = 1;
    int lastpos = a[0];

    for(int i = 1; i < n; i++)
    {
        if(a[i] - lastpos >= mid)
        {
            ballcount++;

            if(ballcount == m)
            return true;

            lastpos = a[i];
        }
    }
    return false;
}

int findMaxDistance(vector<int> a,int n,int m)
{
    sort(a.begin(),a.end());

    int ans = -1;
    int start = 0;
    int end = a[n-1];

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(isPossible(a,n,m,mid))
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
    vector<int> position = {1,2,3,4,7};
    int m = 3;
    int n = position.size();

    cout << findMaxDistance(position,n,m) << endl;

    return 0;
}