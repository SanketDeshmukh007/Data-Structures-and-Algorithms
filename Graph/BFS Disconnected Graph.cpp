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

    void bfs(int src,unordered_map<int,bool>& visited)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            cout << front << " ";

            for(auto x : adj[front])
            {
                if(!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }
};

int main()
{
    Graph<int> g;
    int n = 5; // no. of nodes
    // Undirected
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,2,1);
    g.addEdge(1,4,1);
    g.addEdge(2,3,1);
    g.addEdge(3,1,1);
    g.printList();
    
    unordered_map<int,bool> visited;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            g.bfs(i,visited);
        }
    }

    return 0;
}