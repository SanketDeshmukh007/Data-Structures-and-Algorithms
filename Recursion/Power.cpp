#include<bits/stdc++.h>
using namespace std;

int Power(int x,int n,int& ans)
{
    // 1. Base Case
    if(n == 0)
    return ans;

    // 2. Processing
    ans = ans * x;

    // 3. Recursive Relation
    return Power(x,n-1,ans);
}

int main()
{
    int ans = 1;
    int x = 2;
    int n = 5;
    // Power(x,n,ans);

    cout << Power(x,n,ans) << endl;

    return 0;
}