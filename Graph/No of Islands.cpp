#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int m, int n, vector<vector<char>> &grid)
{
    if ((i >= 0 and i < m) and (j >= 0 and j < n) and grid[i][j] == '1')
        return true;

    return false;
}

void dfs(int i, int j, int m, int n, vector<vector<char>> &grid)
{
    grid[i][j] = '0';

    if (isValid(i + 1, j, m, n, grid))
        dfs(i + 1, j, m, n, grid);
    if (isValid(i - 1, j, m, n, grid))
        dfs(i - 1, j, m, n, grid);
    if (isValid(i, j + 1, m, n, grid))
        dfs(i, j + 1, m, n, grid);
    if (isValid(i, j - 1, m, n, grid))
        dfs(i, j - 1, m, n, grid);
}

int numIslands(vector<vector<char>> &grid)
{
    int count = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(i, j, m, n, grid);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<char>> grid = {
  {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'},
    };

    cout << numIslands(grid) << endl;

    return 0;
}