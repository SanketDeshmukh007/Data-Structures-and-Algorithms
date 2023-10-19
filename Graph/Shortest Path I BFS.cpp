#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void addEdge(int u,int v,int weight,bool direction)
    {
        // direction = 0 -- Undirected
        // direction = 1 -- Directed
        adj[u].push_back({v,weight});
        if(direction == 0)
            adj[v].push_back({u,weight});
    }

    void printList()
    {
        for(auto x : adj)
        {
            cout<<x.first<<"-->";
            for(auto y : x.second)
            {
                cout << "(" << y.first << "," << y.second << ") ";
            }
            cout << endl;
        }
    }

    void shortestPathBFS(int src,int dest)
    {
        queue<int> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            for(auto x : adj[front])
            {
                int node = x.first;
                // int wt = x.second;
                if(!visited[node])
                {
                    q.push(node);
                    visited[node] = true;
                    parent[node] = front;
                }
            }
        }

        vector<int> ans;
        int node = dest;
        while(node != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin(),ans.end());
        for(auto x : ans)
        cout << x << " ";
        cout << endl;
    }
};

int main()
{
    Graph g;
    g.addEdge(0,1,1,0);
    g.addEdge(0,5,1,0);
    g.addEdge(0,6,1,0);
    g.addEdge(1,2,1,0);
    g.addEdge(6,3,1,0);
    g.addEdge(2,3,1,0);
    g.addEdge(5,4,1,0);
    g.addEdge(4,4,1,0);
    g.printList();

    g.shortestPathBFS(0,3);

    return 0;
}