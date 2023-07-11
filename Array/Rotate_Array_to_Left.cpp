#include<bits/stdc++.h>
using namespace std;

void RotateLeft(vector<int> a,int n,int k)
{
    vector<int> temp;

    for(int i = k; i < n; i++)
    {
        temp.push_back(a[i]);
    }

    for(int i = 0; i < k; i++)
    {
        temp.push_back(a[i]);
    }

    for(auto x : temp)
    cout << x << " ";
}

int main()
{
    vector<int> arr = {10,20,30,40,50,60,70};
    int n = arr.size();
    int k = 3;
    RotateLeft(arr,n,k);

    return 0;
}