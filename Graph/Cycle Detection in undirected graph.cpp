#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        // direction = 0 -- Undirected
        // direction = 1 -- Directed
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

    unordered_map<int, int> parent;
    bool detectBFS(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto x : adj[front])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                    parent[x] = front;
                }
                else
                {
                    // Already Visited
                    if (x != parent[front])
                        return true;
                }
            }
        }
        return false;
    }

    bool detectDFS(int src,unordered_map<int,bool>& visited,int parent)
    {
        visited[src] = true;

        for(auto x : adj[src])
        {
            if(!visited[x])
            {
                bool Ans = detectDFS(x,visited,src);
                if(Ans == true)
                    return true;
            }
            else
            {
                if(x != parent)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Graph<int> g;
    int n = 5; // no. of nodes
    // Undirected
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 4, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(4, 3, 0);
    g.printList();

    unordered_map<int, bool> visited;
    bool ans;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = g.detectDFS(i, visited, -1);

            if (ans == true)
                break;
        }
    }
        
    if(ans) cout << "Cycle is present" << endl;
    else cout << "Cycle is not present" << endl;

    return 0;
}