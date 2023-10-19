#include <bits/stdc++.h>
using namespace std;

int dijkstra(int V, unordered_map<int, list<pair<int, int>>> &adj, int S, int &threshold)
{
    set<pair<int, int>> s;
    vector<int> dist(V, INT_MAX);
    int reachableCities = 0; // cities having dist <= threshold

    s.insert({0, S});
    dist[S] = 0;

    while (!s.empty())
    {
        auto front = *(s.begin());
        int dis = front.first;
        int Node = front.second;
        s.erase(front);

        if (Node != S and dis <= threshold)
            reachableCities++;

        for (auto x : adj[Node])
        {
            int node = x.first;
            int wt = x.second;
            if (dis + wt < dist[node])
            {
                if (dist[node] != INT_MAX)
                {
                    s.erase({dist[node], node});
                }

                dist[node] = dis + wt;
                s.insert({dist[node], node});
            }
        }
    }

    return reachableCities;
}

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (auto x : edges)
    {
        int u = x[0];
        int v = x[1];
        int wt = x[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int city = 0;
    int minReachableCities = INT_MAX;
    for (int u = 0; u < n; u++)
    {
        int reachableCitiesCount = dijkstra(n, adj, u, distanceThreshold);

        if (reachableCitiesCount <= minReachableCities)
        {
            minReachableCities = reachableCitiesCount;
            city = u;
        }
    }

    return city;
}

int main()
{
    //

    return 0;
}