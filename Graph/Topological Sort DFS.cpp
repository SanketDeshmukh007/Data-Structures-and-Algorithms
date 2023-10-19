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

	vector<int> topoSort(int V) 
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
	    
	    vector<int> ans;
	    while(!s.empty())
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};

int main()
{
    Graph<int> g;
    int n = 5; // no. of nodes
    // Undirected
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);
    g.printList();
    
    vector<int> ans = g.topoSort(n);
    for(auto x : ans)
    cout << x << " ";

    return 0;
}