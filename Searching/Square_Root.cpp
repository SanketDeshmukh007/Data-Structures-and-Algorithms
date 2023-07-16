#include<bits/stdc++.h>
using namespace std;

int squareRoot(int n)
{
    int start = 0;
    int end = n;
    int ans = 0;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(mid * mid <= n)
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
    int n = 25;

    cout << squareRoot(n) << endl;

    return 0;
}