#include<bits/stdc++.h>
using namespace std;

bool LinearSearch(int a[],int n,int target)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == target)
        return true;
    }
    return false;
}

int main()
{
    int a[] = {3,2,54,17,86,43};
    int n = sizeof(a)/sizeof(int);
    bool ans = LinearSearch(a,n,86);
    if(ans)
    cout << "Present" << endl;
    else cout << "Absent" << endl;

    return 0;
}