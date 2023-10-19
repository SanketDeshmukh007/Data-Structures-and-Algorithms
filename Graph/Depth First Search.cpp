#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph
{
    public:
    unordered_map<T,list<T>> adj;

    void addEdge(T u,T v,bool direction)
    {
        // direction = 0 -- Undirected
        // direction = 1 -- Directed
        adj[u].push_back(v);
        if(direction == false)
            adj[v].push_back(u);
    }

    void printList()
    {
        for(auto x : adj)
        {
            cout << x.first << "-->";
            for(auto y : x.second)
                cout << y << " ";
            cout << endl;
        }
    }

    void dfs(int src,unordered_map<int,bool>& visited)
    {
        cout << src << " ";
        visited[src] = true;

        for(auto x : adj[src])
        {
            if(!visited[x])
            {
                dfs(x,visited);
            }
        }
    }
};

int main()
{
    Graph<int> g;
    int n = 5; // no. of nodes
    // Undirected
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,5,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);
    g.printList();
    
    unordered_map<int,bool> visited;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            g.dfs(i,visited);
        }
    }

    return 0;
}