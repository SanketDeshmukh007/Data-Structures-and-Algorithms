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

    void dfs(int src,unordered_map<int,bool>& visited,stack<int>& s)
    {
        visited[src] = true;

        for(auto x : adj[src])
        {
            if(!visited[x])
            {
                dfs(x,visited,s);
            }
        }
        s.push(src);
    }

    stack<int> topoSort(int n)
    {
        stack<int> s;
        unordered_map<int,bool> visited;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,s);
            }
        }
        return s;
    }

    void dfs3(int src,unordered_map<int,bool>& visited,unordered_map<int,list<int>> adjNew)
    {
        cout << src << " ";
        visited[src] = true;

        for(auto x : adjNew[src])
        {
            if(!visited[x])
            {
                dfs3(x,visited,adjNew);
            }
        }
    }

    int countSCC(int n)
    {
        // Step 1
        stack<int> s = topoSort(n);

        // Step 2 : Reverse all edges
        unordered_map<int,list<int>> adjNew;
        for(auto x : adj)
        {
            for(auto y : x.second)
            {
                int u = x.first;
                int v = y;

                adjNew[v].push_back(u);
            }
        }

        // Step 3 : Traverse Graph and count
        int count = 0;
        unordered_map<int,bool> visited;
        while(!s.empty())
        {
            int node = s.top();
            s.pop();

            if(!visited[node])
            {
                cout << "Printing " << count + 1 << " th Component : " << endl;
                dfs3(node,visited,adjNew);
                cout << endl;
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 0, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(6, 7, 1);
    g.printList();

    int count = g.countSCC(8);
    cout << "No of SCC : " << count << endl;
    return 0;
}