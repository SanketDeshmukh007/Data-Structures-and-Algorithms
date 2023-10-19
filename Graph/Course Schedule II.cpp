#include <bits/stdc++.h>
using namespace std;

vector<int> topoSortBFS(int n, unordered_map<int, list<int>> adj)
{
    unordered_map<int, int> Indegree;
    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        for (auto x : adj[i])
        {
            Indegree[x]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (Indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);
        for (auto x : adj[front])
        {
            Indegree[x]--;

            if (Indegree[x] == 0)
                q.push(x);
        }
    }

    if (ans.size() == n)
        return ans;
    else
        return {};
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    unordered_map<int, list<int>> adj;

    for (auto x : prerequisites)
    {
        int u = x[0];
        int v = x[1];

        adj[v].push_back(u);
    }

    return topoSortBFS(numCourses, adj);
}

int main()
{
    //

    return 0;
}