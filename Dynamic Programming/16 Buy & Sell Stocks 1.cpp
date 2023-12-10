#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;

    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    return maxProfit;
}

int main()
{
    //

    return 0;
}