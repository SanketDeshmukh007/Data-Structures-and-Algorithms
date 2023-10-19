#include <bits/stdc++.h>
using namespace std;

void dfs(int src, unordered_map<int, bool> &visited, vector<vector<int>> &isConnected)
{
    visited[src] = true;
    // row = src
    int n = isConnected[src].size();
    for (int col = 0; col < n; col++)
    {
        if (src != col and isConnected[src][col] == 1)
        {
            if (!visited[col])
            {
                dfs(col, visited, isConnected);
            }
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int count = 0;
    unordered_map<int, bool> visited;
    int n = isConnected.size();

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, isConnected);
            count++;
        }
    }
    return count;
}

int main()
{
    //

    return 0;
}