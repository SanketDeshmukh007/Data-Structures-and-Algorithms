#include<bits/stdc++.h>
using namespace std;

int MaximumNumber(int a[],int n)
{
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        maxi = max(maxi,a[i]);
    }
    return maxi;
}

int main()
{
    int a[] = {12,34,52,65,79,123};
    int n = sizeof(a)/sizeof(int);
    cout << MaximumNumber(a,n) << endl;

    return 0;
}