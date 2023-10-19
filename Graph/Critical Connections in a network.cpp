#include <bits/stdc++.h>
using namespace std;

void findBridges(int src, int parent, int &timer, vector<int> &tin, vector<int> &tlow, unordered_map<int, bool> &visited, vector<vector<int>> &ans, unordered_map<int, list<int>> &adj)
{
    visited[src] = true;
    tin[src] = timer;
    tlow[src] = timer;
    timer++;

    for (auto x : adj[src])
    {
        if (x == parent)
            continue;
        if (!visited[x])
        {
            // dfs call
            findBridges(x, src, timer, tin, tlow, visited, ans, adj);
            // Update Low
            tlow[src] = min(tlow[src], tlow[x]);
            // Check for bridge
            if (tlow[x] > tin[src])
            {
                vector<int> temp;
                temp.push_back(x);
                temp.push_back(src);
                ans.push_back(temp);
            }
        }
        else
        {
            // node is visited and not a parent
            // Update low
            tlow[src] = min(tlow[src], tlow[x]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    unordered_map<int, list<int>> adj;

    for (auto x : connections)
    {
        int u = x[0];
        int v = x[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    int timer = 1;
    vector<int> tin(n);
    vector<int> tlow(n);
    unordered_map<int, bool> visited;
    findBridges(0, -1, timer, tin, tlow, visited, ans, adj);
    return ans;
}

int main()
{
    //

    return 0;
}