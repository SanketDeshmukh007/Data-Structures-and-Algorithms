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
};

int main()
{
    Graph g;
    g.addEdge(0,1,3,1);
    g.addEdge(0,3,8,1);
    g.addEdge(1,2,5,1);
    g.addEdge(3,1,6,1);
    g.printList();

    return 0;
}