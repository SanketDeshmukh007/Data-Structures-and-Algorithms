#include<bits/stdc++.h>
using namespace std;

void Reverse(vector<int> &a,int start,int end)
{
    while(start <= end)
    {
        swap(a[start++],a[end--]);
    }
}

void RotateRight(vector<int> &a,int n,int k)
{
    // step 1. reverse left part
    Reverse(a,0,k);

    // step 2. reverse right part
    Reverse(a,k+1,n-1);

    // step 3. reverse whole array
    Reverse(a,0,n-1);
}

int main()
{
    vector<int> arr = {10,20,30,40,50,60,70};
    int n = arr.size();
    int k = 3;
    RotateRight(arr,n,k);
    for(auto x : arr)
    cout << x << " ";

    return 0;
}