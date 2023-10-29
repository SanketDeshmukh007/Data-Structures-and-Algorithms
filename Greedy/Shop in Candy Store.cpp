#include <bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int N, int k)
{
    vector<int> ans;
    sort(candies, candies + N);
    // for(int i = 0; i < N; i++)
    //     cout << candies[i] << " ";
    int buy = 0;
    int fre = N - 1;
    int amount = 0;
    while (buy <= fre)
    {
        amount += candies[buy++];
        fre -= k;
    }
    ans.push_back(amount);
    // cout << amount << endl;

    buy = N - 1;
    fre = 0;
    amount = 0;
    while (buy >= fre)
    {
        amount += candies[buy];
        buy--;
        fre += k;
    }
    ans[1] = amount;
    return ans;
}

int main()
{
    //

    return 0;
}