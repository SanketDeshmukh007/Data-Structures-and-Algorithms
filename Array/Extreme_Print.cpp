#include<bits/stdc++.h>
using namespace std;

void ExtremePrint(int a[],int n)
{
    int start = 0 , end = n - 1;
    while(start <= end)
    {
        if(start == end)
        cout << start << endl;

        cout << a[start] << " ";
        cout << a[end] << " ";

        start++;
        end--;
    }
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(a)/sizeof(int);
    ExtremePrint(a,n);

    return 0;
}