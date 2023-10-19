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

    void FloydWarshallAlgo(int n)
    {
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        for(int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        for(auto x : adj)
        {
            for(auto y : x.second)
            {
                int u = x.first;
                int v = y.first;
                int wt = y.second;

                dist[u][v] = wt;
            }
        }

        for(int helper = 0; helper < n; helper++)
        {
            for(int src = 0; src < n; src++)
            {
                for(int dest = 0; dest < n; dest++)
                {
                    dist[src][dest] = min(dist[src][dest],dist[src][helper] + dist[helper][dest]);
                }
            }
        }

        cout << "Printing Distance Array" << endl;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << dist[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 3, 1);
    g.addEdge(0, 3, 5, 1);
    g.addEdge(1, 0, 2, 1);
    g.addEdge(1, 3, 4, 1);
    g.addEdge(2, 1, 1, 1);
    g.addEdge(3, 2, 2, 1);
    g.printList();

    g.FloydWarshallAlgo(4);

    return 0;
}