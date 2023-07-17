#include<bits/stdc++.h>
using namespace std;

void MaxElement(int *arr,int n,int& maxi)
{
    // 1. Base Case
    if(n == 0)
    return;

    // 2. Processing
    maxi = max(maxi,*arr);

    // 3. Recursive Relation
    MaxElement(arr+1,n-1,maxi);
}

int main()
{
    int arr[] = {10,5,14,31,27,85,43,52};
    int n = sizeof(arr)/sizeof(int);
    int maxi = INT_MIN;
    MaxElement(arr,n,maxi);

    cout << "Maximum number is : " << maxi << endl;

    return 0;
}