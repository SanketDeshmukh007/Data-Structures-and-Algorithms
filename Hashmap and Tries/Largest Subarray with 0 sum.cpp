#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &A, int n)
{
    unordered_map<int, int> m;
    int ans = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += A[i];

        if (sum == 0)
        {
            ans = max(ans, i + 1);
        }
        else if (m.find(sum) == m.end())
        {
            m[sum] = i;
        }
        else
        {
            ans = max(ans, i - m[sum]);
        }
    }
    return ans;
}

int main()
{
    //

    return 0;
}