#include <bits/stdc++.h>
using namespace std;

int minStoneSum(vector<int> &piles, int k)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int> p;

    int n = piles.size();
    for (int i = 0; i < n; i++)
    {
        p.push(piles[i]);
    }

    for (int i = 0; i < k; i++)
    {
        int num = p.top();
        p.pop();

        if (num & 1)
        {
            int res = num / 2;
            res += 1;
            p.push(res);
        }
        else
        {
            p.push(num / 2);
        }
    }

    int sum = 0;
    while (!p.empty())
    {
        sum += p.top();
        p.pop();
    }
    return sum;
}

int main()
{
    //

    return 0;
}