#include <bits/stdc++.h>
using namespace std;

int getMinValueNode(vector<int> key, vector<bool> MST, int n)
{
    int mini = INT_MAX;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (MST[i] == false and key[i] < mini)
        {
            mini = key[i];
            index = i;
        }
    }
    return index;
}
// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    // Initialization
    vector<int> key(V, INT_MAX);
    vector<bool> MST(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;

    while (true)
    {
        // Step 1 : find node with minimum value in key[]
        int u = getMinValueNode(key, MST, V);

        if (u == -1)
            break;

        // Step 2 :
        MST[u] = true;

        // Step 3:
        for (auto x : adj[u])
        {
            int v = x[0];
            int wt = x[1];

            if (MST[v] == false and wt < key[v])
            {
                key[v] = wt;
                parent[v] = u;
            }
        }
    }

    // Find weights
    int sum = 0;
    for (int u = 0; u < V; u++)
    {
        if (parent[u] == -1)
            continue;

        for (auto x : adj[u])
        {
            int v = x[0];
            int wt = x[1];

            if (parent[u] == v)
            {
                sum += wt;
            }
        }
    }
    return sum;
}

int main()
{
    //

    return 0;
}