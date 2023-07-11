#include<bits/stdc++.h>
using namespace std;

int MissingElement(int a[],int n)
{
    int sumOfNum = accumulate(a,a+n-1,0);
    int sum = (n * (n + 1))/2;

    return sum - sumOfNum;
}

int main()
{
    int a[] = {2,3,4,1,6,7};
    int n = 7;

    cout << MissingElement(a,n) << endl;

    return 0;
}