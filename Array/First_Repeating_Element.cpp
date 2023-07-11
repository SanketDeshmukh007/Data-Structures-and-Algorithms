#include<bits/stdc++.h>
using namespace std;

int FirstRepeatingElement(int a[],int n)
{
    unordered_map<int,int> m;

    for(int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }

    for(int i = 0; i < n; i++)
    {
        if(m[a[i]] > 1)
        return i + 1;
    }

    return -1;
}

int main()
{
    int a[] = {10,5,3,4,4,5,6};
    int n = sizeof(a)/sizeof(int);

    cout << FirstRepeatingElement(a,n) << endl;

    return 0;
}