#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

double fractionalKnapsack(int W, Item arr[], int n)
{
    vector<pair<double, int>> v;
    for (int i = 0; i < n; i++)
    {
        int val = arr[i].value;
        int wt = arr[i].weight;
        double ratio = double(val) / wt;
        v.push_back({ratio, i});
    }

    sort(v.begin(), v.end(), greater<pair<double, int>>());

    int i = 0;
    double amount = 0;
    while (W > 0 && i < n)
    {
        double ratio = v[i].first;
        int itemIndex = v[i].second;
        int wt = arr[itemIndex].weight;

        if (wt <= W)
        {
            amount += ratio * wt;
            W -= wt;
        }
        else
        {
            amount += ratio * W;
            W = 0;
        }

        i++;
    }
    return amount;
}

int main()
{
    //

    return 0;
}