#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -- Undirected
        // direction = 1 -- Directed
        adj[u].push_back(v);
        if (direction == 0)
            adj[v].push_back(u);
    }

    void printList()
    {
        for (auto x : adj)
        {
            cout << x.first << "-->";
            for (auto y : x.second)
            {
                cout << y << " ";
            }
            cout << endl;
        }
    }

    void findBridges(int src,int parent,int& timer,vector<int>& tin,vector<int>& tlow,unordered_map<int,bool>& visited)
    {
        visited[src] = true;
        tin[src] = timer;
        tlow[src] = timer;
        timer++;

        for(auto x : adj[src])
        {
            if(x == parent)
            continue;
            if(!visited[x])
            {
                // dfs call
                findBridges(x,src,timer,tin,tlow,visited);
                // Update Low
                tlow[src] = min(tlow[src],tlow[x]);
                // Check for bridge
                if(tlow[x] > tin[src])
                {
                    cout << src << "---" << x << " is a Bridge" << endl;
                }
            }
            else
            {
                // node is visited and not a parent
                // Update low
                tlow[src] = min(tlow[src],tlow[x]);
            }
        }
    }
};

int main()
{
    // Graph g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(0, 2, 0);
    // g.addEdge(2, 1, 0);
    // g.addEdge(0, 3, 0);
    // g.addEdge(3, 4, 0);
    // g.printList();

    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 1, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(1, 6, 0);
    g.addEdge(1, 4, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(4, 5, 0);
    g.printList();

    int n =7;
    int timer = 1;
    vector<int> tin(n);
    vector<int> tlow(n);
    unordered_map<int,bool> visited;
    g.findBridges(0,-1,timer,tin,tlow,visited);

    return 0;
}