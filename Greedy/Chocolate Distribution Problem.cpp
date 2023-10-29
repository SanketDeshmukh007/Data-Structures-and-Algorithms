#include <bits/stdc++.h>
using namespace std;

int findMinDiff(vector<int> a, int n, int m)
{
    // code
    sort(a.begin(), a.end());
    int ans = INT_MAX;

    for (int i = 0; i <= n - m; i++)
    {
        int mini = a[i];
        int maxi = a[i + m - 1];
        cout << mini << " " << maxi << endl;
        int diff = maxi - mini;
        ans = min(ans, diff);
    }
    return ans;
}

int main()
{
    int n = 6, m = 4;
    vector<int> a = {11, 13, 7, 5, 13, 12};
    cout << findMinDiff(a, n, m) << endl;

    return 0;
}