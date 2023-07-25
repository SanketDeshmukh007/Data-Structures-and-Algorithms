#include <bits/stdc++.h>
using namespace std;

bool is_safe(vector<vector<int>> m, int n, vector<vector<bool>> &visited, int i, int j)
{
    if ((i >= 0 and i < n) and (j >= 0 and j < n) and (m[i][j] == 1) and (visited[i][j] == false))
        return true;
    else
        return false;
}

void find(vector<vector<int>> m, int n, vector<vector<bool>> &visited, int i, int j, string output, vector<string> &ans)
{
    // Base Case
    if (i == n - 1 and j == n - 1)
    {
        // Destination is reached
        ans.push_back(output);
        return;
    }

    // Down
    if (is_safe(m, n, visited, i + 1, j))
    {
        visited[i + 1][j] = true;
        find(m, n, visited, i + 1, j, output + 'D', ans);
        visited[i + 1][j] = false;
    }

    // Left
    if (is_safe(m, n, visited, i, j - 1))
    {
        visited[i][j - 1] = true;
        find(m, n, visited, i, j - 1, output + 'L', ans);
        visited[i][j - 1] = false;
    }

    // Right
    if (is_safe(m, n, visited, i, j + 1))
    {
        visited[i][j + 1] = true;
        find(m, n, visited, i, j + 1, output + 'R', ans);
        visited[i][j + 1] = false;
    }

    // Up
    if (is_safe(m, n, visited, i - 1, j))
    {
        visited[i - 1][j] = true;
        find(m, n, visited, i - 1, j, output + 'U', ans);
        visited[i - 1][j] = false;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    if (m[0][0] == 0)
        return ans;

    string output = "";
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;
    int i = 0, j = 0;
    find(m, n, visited, i, j, output, ans);
    return ans;
}

int main()
{
    int N = 4;
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};

    vector<string> ans = findPath(m, N);
    for (auto x : ans)
        cout << x << " ";

    return 0;
}