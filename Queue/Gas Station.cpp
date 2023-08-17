#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int balance = 0;
    int need = 0;
    int start = 0;
    int n = gas.size();

    for (int i = 0; i < n; i++)
    {
        balance += gas[i] - cost[i];
        if (balance < 0)
        {
            need += balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (balance + need >= 0)
        return start;
    else
        return -1;
}

int main()
{
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout << canCompleteCircuit(gas,cost) << endl;

    return 0;
}