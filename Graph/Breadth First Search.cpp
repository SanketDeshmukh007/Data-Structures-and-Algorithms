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

    void bfs(int src)
    {
        queue<int> q;
        unordered_map<int,bool> visited;
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
    // Undirected
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,5,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);
    g.printList();
    g.bfs(0);

    // Directed
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(0,2,1);
    // g.printList();

    return 0;
}