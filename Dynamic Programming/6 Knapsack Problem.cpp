#include <bits/stdc++.h>
using namespace std;

// index -- index of last element
// TC - O(EXponential)
int knapsackRec(int W, int wt[], int val[], int index)
{
    // Base Case
    if (index == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }

    // include
    int include = 0;
    if (wt[index] <= W)
        include = val[index] + knapsackRec(W - wt[index], wt, val, index - 1);
    int exclude = knapsackRec(W, wt, val, index - 1);

    return max(include, exclude);
}

// TC - O(N * M)
int knapsackMem(int W, int wt[], int val[], int index, vector<vector<int>> &dp)
{
    // Base Case
    if (index == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }

    if (dp[index][W] != -1)
        return dp[index][W];

    // include
    int include = 0;
    if (wt[index] <= W)
        include = val[index] + knapsackMem(W - wt[index], wt, val, index - 1, dp);
    int exclude = knapsackMem(W, wt, val, index - 1, dp);

    dp[index][W] = max(include, exclude);
    return dp[index][W];
}

int knapsackTab(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int i = wt[0]; i <= W; i++)
    {
        if (wt[0] <= W)
            dp[0][i] = val[0];
        else
            dp[0][i] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int capacity = 0; capacity <= W; capacity++)
        {
            int include = 0;
            if (wt[index] <= capacity)
                include = val[index] + dp[index - 1][capacity - wt[index]];
            int exclude = dp[index - 1][capacity];

            dp[index][capacity] = max(include, exclude);
        }
    }

    return dp[n - 1][W];
}

// SC - O(N)
int knapsackSO(int W, int wt[], int val[], int n)
{
    vector<int> prev(W + 1, 0);
    vector<int> curr(W + 1, 0);

    for (int i = wt[0]; i <= W; i++)
    {
        if (wt[0] <= W)
            prev[i] = val[0];
        else
            prev[i] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int capacity = 0; capacity <= W; capacity++)
        {
            int include = 0;
            if (wt[index] <= capacity)
                include = val[index] + prev[capacity - wt[index]];
            int exclude = prev[capacity];

            curr[capacity] = max(include, exclude);
        }
        prev = curr;
    }

    return prev[W];
}

int knapsackSO2(int W, int wt[], int val[], int n)
{
    vector<int> curr(W + 1, 0);

    for (int i = wt[0]; i <= W; i++)
    {
        if (wt[0] <= W)
            curr[i] = val[0];
        else
            curr[i] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int capacity = W; capacity >= 0; capacity--)
        {
            int include = 0;
            if (wt[index] <= capacity)
                include = val[index] + curr[capacity - wt[index]];
            int exclude = curr[capacity];

            curr[capacity] = max(include, exclude);
        }
    }

    return curr[W];
}
// Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    // return knapsackRec(W,wt,val,n-1);

    //   vector<vector<int>> dp(n,vector<int>(W+1,-1));
    //   return knapsackMem(W,wt,val,n-1,dp);

    return knapsackSO2(W, wt, val, n);
}

int main()
{
    //

    return 0;
}