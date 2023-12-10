#include <bits/stdc++.h>
using namespace std;

#define INF (1e9 + 7)

int solve(vector<int> &a, vector<int> &b, int prev, int i)
{
    if (i == a.size())
        return 0;

    int op1 = INF;
    if (a[i] > prev)
        op1 = solve(a, b, a[i], i + 1);
    int op2 = INF;
    auto it = upper_bound(b.begin(), b.end(), prev);
    if (it != b.end())
    {
        int index = it - b.begin();
        // a[i] = b[index]
        prev = b[index];
        op2 = 1 + solve(a, b, prev, i + 1);
    }

    return min(op1, op2);
}

int solveMem(vector<int> &a, vector<int> &b, int prev, int i, map<pair<int, int>, int> &dp)
{
    if (i == a.size())
        return 0;
    if (dp.find({prev, i}) != dp.end())
        return dp[{prev, i}];

    int op1 = INF;
    if (a[i] > prev)
        op1 = solveMem(a, b, a[i], i + 1, dp); // No Operation
    int op2 = INF;
    auto it = upper_bound(b.begin(), b.end(), prev);
    if (it != b.end())
    {
        int index = it - b.begin();
        // a[i] = b[index]
        prev = b[index];
        op2 = 1 + solveMem(a, b, prev, i + 1, dp);
    }

    return dp[{prev, i}] = min(op1, op2);
}

int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
{
    // 1. Recursion
    // sort(arr2.begin(),arr2.end());
    // int ans = solve(arr1,arr2,-1,0);
    // if(ans == INF) return -1;
    // return ans;
    // 2. Memoization
    sort(arr2.begin(), arr2.end());
    map<pair<int, int>, int> dp;
    int ans = solveMem(arr1, arr2, -1, 0, dp);
    if (ans == INF)
        return -1;
    return ans;
}

int main()
{
    //

    return 0;
}