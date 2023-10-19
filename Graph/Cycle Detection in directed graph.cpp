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

    bool dfs(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited)
    {
        visited[src] = true;
        dfsvisited[src] = true;

        for (auto x : adj[src])
        {
            if (!visited[x])
            {
                bool Ans = dfs(x, visited, dfsvisited);
                if (Ans == true)
                    return true;
            }
            else
            {
                if (dfsvisited[x] == true)
                    return true;
            }
        }
        dfsvisited[src] = false;
        return false;
    }

    vector<int> topoSort(int n)
    {
        queue<int> q;
        vector<int> ans;
        unordered_map<int,int> Indegree;
        
        for(int i = 0; i < n; i++)
        {
            for(auto x : adj[i])
            {
                Indegree[x]++;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(Indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            ans.push_back(front);
            
            for(auto x : adj[front])
            {
                Indegree[x]--;
                
                if(Indegree[x] == 0)
                    q.push(x);
            }
        }
        return ans;
    }
};

int main()
{
    Graph<int> g;
    int n = 4; // no. of nodes
    // Undirected
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, 1);
    g.printList();

    // 1. Using DFS
    // bool ans;
    // unordered_map<int, bool> visited;
    // unordered_map<int, bool> dfsvisited;

    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         ans = g.dfs(i, visited, dfsvisited);
    //         if (ans == true)
    //             break;
    //     }
    // }

    // Using BFS
    vector<int> ans = g.topoSort(n);

    if (int(ans.size()) != n)
        cout << "Cycle is present" << endl;
    else
        cout << "Cycle is not present" << endl;

    return 0;
}