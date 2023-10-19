#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == false)
            adj[v].push_back(u);
    }

    void printList()
    {
        for (auto x : adj)
        {
            cout << x.first << "-->";
            for (auto y : x.second)
                cout << y << " ";
            cout << endl;
        }
    }

    void dfs(T src, unordered_map<T, bool>& visited)
    {
        cout << src << " ";
        visited[src] = true;

        for (auto x : adj[src])
        {
            if (!visited[x])
            {
                dfs(x, visited);
            }
        }
    }

    int countConnectedComponents()
    {
        int count = 0;
        unordered_map<T, bool> visited;

        for (auto x : adj)
        {
            if (!visited[x.first])
            {
                dfs(x.first, visited);
                count++;
                cout << endl; // Add a line break to separate components
            }
        }

        return count;
    }
};

int main()
{
    Graph<int> g;
    int n = 5; // no. of nodes

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 1, 1);
    g.printList();

    int count = g.countConnectedComponents();

    cout << "Number of connected components: " << count << endl;

    return 0;
}
