#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> a, int m, int n, int mid)
{
    int shipcount = 1;
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        if (total + a[i] <= mid)
            total += a[i];
        else
        {
            shipcount++;

            if (shipcount > m or a[i] > mid)
                return false;

            total = 0;
            total += a[i];
        }
    }
    return true;
}

int shipWithinDays(vector<int> &weights, int days)
{

    int ans = -1;
    int m = days;
    int n = weights.size();

    int start = *max_element(weights.begin(), weights.end());
    int end = accumulate(weights.begin(), weights.end(), 0);

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(weights, m, n, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    return ans;
}

int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    cout << shipWithinDays(weights,days) << endl;

    return 0;
}