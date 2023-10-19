#include<bits/stdc++.h>
using namespace std;

template<typename T>

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

    void dfs(int src,unordered_map<int,bool>& visited,stack<int>& s)
	{
	    visited[src] = true;
	    
	    for(auto x : adj[src])
	    {
	        if(!visited[x.first])
	        {
	            dfs(x.first,visited,s);
	        }
	    }
	    
	    s.push(src);
	}

	stack<int> topoSort(int V) 
	{
	    stack<int> s;
	    unordered_map<int,bool> visited;
	    for(int i = 0; i < V; i++)
	    {
	        if(!visited[i])
	        {
	            dfs(i,visited,s);
	        }
	    }
	    
	    return s;
	}

    void shortestPathDFS(int n,stack<int> s)
    {
        vector<int> dist(n,INT_MAX);

        int src = s.top();
        s.pop();
        dist[src] = 0;

        for(auto x : adj[src])
        {
            if(dist[src] + x.second < dist[x.first])
            {
                dist[x.first] = dist[src] + x.second;
            }
        }

        while(!s.empty())
        {
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX)
            {
                for(auto x : adj[top])
                {
                    if(dist[top] + x.second < dist[x.first])
                    {
                        dist[x.first] = dist[top] + x.second;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            cout << i << "-->" << dist[i] << endl;
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,1,2,1);
    g.addEdge(2,4,6,1);
    g.addEdge(1,3,3,1);
    g.addEdge(2,3,3,1);
    g.addEdge(4,3,1,1);
    g.printList();
    
    stack<int> s = g.topoSort(5);
    // while(!s.empty())
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    g.shortestPathDFS(5,s);

    return 0;
}