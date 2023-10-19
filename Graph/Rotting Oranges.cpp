#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int m, int n, vector<vector<int>> &grid)
{
    if ((i >= 0 and i < m) and (j >= 0 and j < n) and grid[i][j] == 1)
        return true;

    return false;
}

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    int time = 0;

    int fresh = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
            else if (grid[i][j] == 1)
            {
                fresh++;
            }
        }
    }

    if (fresh == 0)
        return 0;

    while (!q.empty())
    {
        int size = q.size();
        int temp = 0;

        for (int i = 0; i < size; i++)
        {
            pair<int, int> p = q.front();
            q.pop();

            int x = p.first;
            int y = p.second;

            int ax[4] = {1, -1, 0, 0};
            int ay[4] = {0, 0, 1, -1};

            for (int i = 0; i < 4; i++)
            {
                if (isValid(x + ax[i], y + ay[i], m, n, grid))
                {
                    grid[x + ax[i]][y + ay[i]] = 2;
                    q.push({x + ax[i], y + ay[i]});
                    temp++;
                }
            }
        }
        if (temp != 0)
            time++;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }

    return time;
}

int main()
{
    // Create a 2D vector representing the grid with oranges
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};

    // Call your orangesRotting function and print the result
    int result = orangesRotting(grid);

    // Display the result
    if (result == -1)
    {
        cout << "It's not possible to rot all oranges." << endl;
    }
    else
    {
        cout << "Minimum time to rot all oranges: " << result << " minutes." << endl;
    }

    return 0;
}