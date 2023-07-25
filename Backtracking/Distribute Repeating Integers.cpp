#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &count, vector<int> &quantity, int ithCustomer)
{
    // Base Case
    if (ithCustomer >= int(quantity.size()))
        return true;

    for (int i = 0; i < int(count.size()); i++)
    {
        if (count[i] >= quantity[ithCustomer])
        {
            count[i] -= quantity[ithCustomer];
            if (solve(count, quantity, ithCustomer + 1))
                return true;
            // Backtracking
            count[i] += quantity[ithCustomer];
        }
    }

    return false;
}

bool canDistribute(vector<int> &nums, vector<int> &quantity)
{
    unordered_map<int, int> m;
    for (auto x : nums)
    {
        m[x]++;
    }
    vector<int> count;
    for (auto x : m)
        count.push_back(x.second);

    sort(quantity.rbegin(), quantity.rend()); // Sorting in descending order
    return solve(count, quantity, 0); // 0 is 0th customer
}

int main()
{
    vector<int> nums = {1,1,2,2,2,2,3,3}, quantity = {2,2,3};
    cout << canDistribute(nums,quantity) << endl;

    return 0;
}