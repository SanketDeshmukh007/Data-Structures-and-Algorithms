#include <bits/stdc++.h>
using namespace std;

int findCost(vector<int> &days, vector<int> &costs, int i)
{
    // Base Case
    if (i >= int(days.size()))
        return 0;

    // solution for 1 case

    // 1 day pass taken
    int cost1 = costs[0] + findCost(days, costs, i + 1);

    // 7 day pass taken
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while (j < int(days.size()) and days[j] <= passEndDay)
    {
        j++;
    }
    int cost7 = costs[1] + findCost(days, costs, j);

    // 30 days pass taken
    passEndDay = days[i] + 30 - 1;
    j = i;
    while (j < int(days.size()) and days[j] <= passEndDay)
    {
        j++;
    }
    int cost30 = costs[2] + findCost(days, costs, j);

    return min(cost1, min(cost7, cost30));
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return findCost(days, costs, 0);
}

int main()
{
    vector<int> days = {1,4,6,7,8,20}, costs = {2,7,15};

    cout << mincostTickets(days,costs) << endl;

    return 0;
}