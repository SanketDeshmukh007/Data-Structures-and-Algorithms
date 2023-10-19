#include <bits/stdc++.h>
using namespace std;

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent, parent[node]);
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

int makeConnected(int n, vector<vector<int>> &connections)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> parent(n);
    vector<int> sz(n, 0);

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }

    int extraEdges = 0;
    for (auto x : connections)
    {
        int u = x[0];
        int v = x[1];

        u = findParent(parent, u);
        v = findParent(parent, v);

        if (u == v)
        {
            extraEdges++;
        }
        else
        {
            unionSet(u, v, parent, sz);
        }
    }

    int nocc = 0; // number of connected components
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i)
            nocc++;
    }

    int ans = nocc - 1;
    if (extraEdges >= ans)
        return ans;

    return -1;
}

int main()
{
    //

    return 0;
}