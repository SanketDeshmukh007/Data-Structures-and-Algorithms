#include<bits/stdc++.h>
using namespace std;

void rotateLeft(vector<int> &a,int k)
{
    rotate(a.begin(),a.begin()+k,a.end());
}

void rotateRight(vector<int> &a,int k)
{
    rotate(a.begin(),a.begin()+a.size()-k,a.end());
}

int main()
{
    vector<int> a = {1,2,3,4,5,6,7};
    // rotateLeft(a,3);
    rotateRight(a,3);
    for(auto x : a)
    cout << x << " ";

    return 0;
}