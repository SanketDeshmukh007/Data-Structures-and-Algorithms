#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    // 1. Base Case
    if(n <= 1)
    return 1;

    // 2. Recursive Relation
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main()
{
    int n = 2;
    cout << climbStairs(n) << endl;

    return 0;
}