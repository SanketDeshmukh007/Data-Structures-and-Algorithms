#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int len = INT_MAX;
    int i = 0;
    int j = 0;
    int n = nums.size();
    int sum = 0;

    while (j < n)
    {
        sum += nums[j];

        while (sum >= target)
        {
            // Minimize the window
            len = min(len, j - i + 1);
            sum -= nums[i];
            i++;
        }
        j++;
    }

    if (len == INT_MAX)
        return 0;

    return len;
}

int main()
{
    //

    return 0;
}