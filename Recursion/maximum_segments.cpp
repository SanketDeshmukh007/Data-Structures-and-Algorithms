#include<bits/stdc++.h>
using namespace std;

int maximumSegments(int n,int x,int y,int z)
{
    // 1. Base case
    if(n == 0)
    return 0;
    else if(n < 0)
    return INT_MIN;

    int ans1 = maximumSegments(n-x,x,y,z) + 1;
    int ans2 = maximumSegments(n-y,x,y,z) + 1;
    int ans3 = maximumSegments(n-z,x,y,z) + 1;

    int ans = max(ans1,max(ans2,ans3));
    return ans;
}

int main()
{
    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;
    int ans = maximumSegments(n,x,y,z);
    if(ans < 0)
    ans = 0;

    cout << ans << endl;

    return 0;
}