#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &piles, int i, int M, bool aliceTurn)
{
    if (i == piles.size())
        return 0;

    int ans = (aliceTurn) ? INT_MIN : INT_MAX;
    int total = 0;

    for (int x = 1; x <= (2 * M); x++)
    {
        if (i + x - 1 >= piles.size())
            break;
        total += piles[i + x - 1];
        if (aliceTurn)
        {
            ans = max(ans, total + solve(piles, i + x, max(x, M), !aliceTurn));
        }
        else
        {
            ans = min(ans, solve(piles, i + x, max(x, M), !aliceTurn));
        }
    }
    return ans;
}

int solveMem(vector<int> &piles, int i, int M, bool aliceTurn, vector<vector<vector<int>>> &dp)
{
    if (i == piles.size())
        return 0;
    if (dp[i][M][aliceTurn] != -1)
        return dp[i][M][aliceTurn];

    int ans = (aliceTurn) ? INT_MIN : INT_MAX;
    int total = 0;

    for (int x = 1; x <= (2 * M); x++)
    {
        if (i + x - 1 >= piles.size())
            break;
        total += piles[i + x - 1];
        if (aliceTurn)
        {
            ans = max(ans, total + solveMem(piles, i + x, max(x, M), !aliceTurn, dp));
        }
        else
        {
            ans = min(ans, solveMem(piles, i + x, max(x, M), !aliceTurn, dp));
        }
    }
    return dp[i][M][aliceTurn] = ans;
}

int solveTab(vector<int> &piles)
{
    int n = piles.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int M = n - 1; M >= 0; M--)
        {
            for (int aliceTurn = 0; aliceTurn <= 1; aliceTurn++)
            {
                int ans = (aliceTurn) ? INT_MIN : INT_MAX;
                int total = 0;

                for (int x = 1; x <= (2 * M); x++)
                {
                    if (i + x - 1 >= piles.size())
                        break;
                    total += piles[i + x - 1];
                    if (aliceTurn)
                    {
                        ans = max(ans, total + dp[i + x][max(x, M)][!aliceTurn]);
                    }
                    else
                    {
                        ans = min(ans, dp[i + x][max(x, M)][!aliceTurn]);
                    }
                }
                dp[i][M][aliceTurn] = ans;
            }
        }
    }
    return dp[0][1][1];
}

int stoneGameII(vector<int> &piles)
{
    // 1. Recursion
    // return solve(piles,0,1,true);

    // 2. Memoization
    // int n = piles.size();
    // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
    // return solveMem(piles,0,1,true,dp);

    // 3. Tabulation
    return solveTab(piles);
}

int main()
{
    //

    return 0;
}