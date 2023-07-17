#include <bits/stdc++.h>
using namespace std;

int numRollsToTarget(int n, int k, int target)
{
    // Base Case
    if (target < 0)
        return 0;
    if (n == 0 and target == 0)
        return 1;
    if (n != 0 and target == 0)
        return 0;
    if (n == 0 and target != 0)
        return 0;

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += numRollsToTarget(n - 1, k, target - i);
    }

    return ans;
}

int main()
{
    cout << numRollsToTarget(3,2,6) << endl;

    return 0;
}