#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    vector<vector<int>> adj(n,vector<int>(n,0));

    int e;
    cout << "Enter number of edges" << endl;
    cin >> e;

    for(int i = 0; i < e; i++)
    {
        int u,v;
        cin >> u >> v;
        // Mark 1
        adj[u][v] = 1;
    }

    // Printing
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << adj[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}