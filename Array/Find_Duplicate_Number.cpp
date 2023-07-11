#include<bits/stdc++.h>
using namespace std;

int DuplicateNumber(int a[])
{
    while(a[0] != a[a[0]])
    {
        swap(a[0],a[a[0]]);
    }
    return a[0];
}

int main()
{
    int a[] = {3,1,3,4,2};
    cout << DuplicateNumber(a) << endl;

    return 0;
}