#include<bits/stdc++.h>
using namespace std;

void Count(int a[],int n)
{
    int countZero = 0;
    int countOne = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0)
        countZero++;
        else 
        countOne++;
    }

    cout << "0 --> " << countZero << endl;
    cout << "1 --> " << countOne << endl;
}

int main()
{
    int a[] = {0,0,0,1,1,1,0,0,1,1,1};
    int n = sizeof(a)/sizeof(int);
    Count(a,n);

    return 0;
}