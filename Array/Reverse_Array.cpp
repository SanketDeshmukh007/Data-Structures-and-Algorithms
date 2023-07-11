#include<bits/stdc++.h>
using namespace std;

void Reverse(int a[],int n)
{
    int start = 0 , end = n - 1;
    while(start <= end)
    {
        swap(a[start++],a[end--]);
    }
}

int main()
{
    int a[] = {12,34,52,65,79,123};
    int n = sizeof(a)/sizeof(int);
    Reverse(a,n);

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}