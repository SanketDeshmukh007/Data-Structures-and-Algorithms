#include <bits/stdc++.h>
using namespace std;

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent, parent[node]); // Path Compression
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &sz)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (sz[u] < sz[v])
    {
        parent[u] = v;
        sz[v]++;
    }
    else
    {
        parent[v] = u;
        sz[u]++;
    }
}
// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> parent(V);
    vector<int> sz(V, 0); // size

    // make all nodes as individual components
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }

    vector<vector<int>> edges;
    for (int u = 0; u < V; u++)
    {
        for (auto x : adj[u])
        {
            int v = x[0];
            int wt = x[1];
            edges.push_back({wt, u, v});
        }
    }

    sort(edges.begin(), edges.end());

    int ans = 0;
    for (auto edge : edges)
    {
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];

        u = findParent(parent, u);
        v = findParent(parent, v);

        // No Cycle
        if (u != v)
        {
            unionSet(u, v, parent, sz);
            ans += w;
        }
    }
    return ans;
}

int main()
{
    //

    return 0;
}