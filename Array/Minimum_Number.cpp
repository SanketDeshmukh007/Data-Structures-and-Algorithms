#include<bits/stdc++.h>
using namespace std;

int MinimumNumber(int a[],int n)
{
    int mini = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        mini = min(mini,a[i]);
    }
    return mini;
}

int main()
{
    int a[] = {12,34,52,65,79,123};
    int n = sizeof(a)/sizeof(int);
    cout << MinimumNumber(a,n) << endl;

    return 0;
}