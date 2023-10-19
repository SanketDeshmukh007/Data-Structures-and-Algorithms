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
};

int main()
{
    // Graph<int> g;
    // Undirected
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);
    // g.printList();

    // Directed
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(0,2,1);
    // g.printList();

    Graph<char> g;
    g.addEdge('a', 'b', 1);
    g.addEdge('b', 'c', 1);
    g.addEdge('a', 'c', 1);
    g.printList();


    return 0;
}