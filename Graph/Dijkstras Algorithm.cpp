#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int, int>> s;
    vector<int> dist(V, INT_MAX);

    s.insert({0, S});
    dist[S] = 0;

    while (!s.empty())
    {
        auto front = *(s.begin());
        int dis = front.first;
        int Node = front.second;
        s.erase(front);

        for (auto x : adj[Node])
        {
            int node = x[0];
            int wt = x[1];
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
    return dist;
}

int main()
{
    // Example usage of the dijkstra function
    int V = 5; // Number of vertices
    int S = 0; // Source vertex

    // Adjacency list representation of the graph
    vector<vector<int>> adj[V];
    adj[0] = {{1, 2}, {2, 4}};
    adj[1] = {{2, 1}, {3, 7}};
    adj[2] = {{3, 3}};
    adj[3] = {{4, 1}};
    adj[4] = {};

    vector<int> shortest_distances = dijkstra(V, adj, S);

    cout << "Shortest distances from vertex " << S << " to all other vertices:\n";
    for (int i = 0; i < V; ++i)
    {
        cout << "Vertex " << i << ": " << shortest_distances[i] << endl;
    }

    return 0;
}
