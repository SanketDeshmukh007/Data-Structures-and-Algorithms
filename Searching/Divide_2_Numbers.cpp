#include<bits/stdc++.h>
using namespace std;

int divide(int dividend,int divisor)
{
    int start = 0;
    int end = dividend;
    int ans = -1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(mid * divisor <= dividend)
        {
            ans = mid;
            start = mid + 1;
        }
        else if(mid * divisor > dividend)
        end = mid - 1;
        else start = mid + 1;
    }
    return ans;
}

int main()
{
    int a = 1000, b = 5;
    cout << divide(a,b) << endl;

    return 0;
}