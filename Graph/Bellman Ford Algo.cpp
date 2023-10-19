#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight, bool direction)
    {
        // direction = 0 -- Undirected
        // direction = 1 -- Directed
        adj[u].push_back({v, weight});
        if (direction == 0)
            adj[v].push_back({u, weight});
    }

    void printList()
    {
        for (auto x : adj)
        {
            cout << x.first << "-->";
            for (auto y : x.second)
            {
                cout << "(" << y.first << "," << y.second << ") ";
            }
            cout << endl;
        }
    }

    void bellmanFordAlgo(int n, int src)
    {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // n - 1 relaxation step
        for (int i = 0; i < (n - 1); i++)
        {
            for (auto x : adj)
            {
                for (auto y : x.second)
                {
                    int u = x.first;
                    int v = y.first;
                    int wt = y.second;

                    if (dist[u] != INT_MAX and dist[u] + wt < dist[v])
                    {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        // To check negative cycle
        bool negCycle = false;
        for (auto x : adj)
        {
            for (auto y : x.second)
            {
                int u = x.first;
                int v = y.first;
                int wt = y.second;

                if (dist[u] != INT_MAX and dist[u] + wt < dist[v])
                {
                    negCycle = true;
                    break;
                }
            }
        }

        if(negCycle) cout << "Cycle is Present" << endl;
        else cout << "Cycle is Absent" << endl;

        for (auto x : dist)
            cout << x << " ";
    }
};

int main()
{
    // Graph g;
    // g.addEdge(0, 1, -1, 1);
    // g.addEdge(0, 2, 4, 1);
    // g.addEdge(1, 2, 3, 1);
    // g.addEdge(1, 3, 2, 1);
    // g.addEdge(1, 4, 2, 1);
    // g.addEdge(3, 1, 1, 1);
    // g.addEdge(3, 2, 5, 1);
    // g.addEdge(4, 3, -3, 1);
    // g.printList();

    // g.bellmanFordAlgo(5, 0);

    Graph g;
    g.addEdge(0, 1, -2, 0);
    g.addEdge(0, 2, -4, 0);
    g.addEdge(1, 2, -3, 0);
    g.printList();

    g.bellmanFordAlgo(3, 0);

    return 0;
}