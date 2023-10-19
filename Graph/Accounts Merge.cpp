#include <bits/stdc++.h>
using namespace std;

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &sz)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (sz[u] < sz[v])
    {
        parent[u] = v;
        sz[v]++;
    }
    else
    {
        parent[v] = u;
        sz[u]++;
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = accounts.size();
    vector<int> parent(n);
    vector<int> sz(n, 0);

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }

    unordered_map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        auto account = accounts[i];
        for (int j = 1; j < account.size(); j++)
        {
            auto mail = account[j];
            auto it = m.find(mail);
            if (it == m.end())
                m[mail] = i;
            else
            {
                unionSet(i, it->second, parent, sz);
            }
        }
    }

    unordered_map<int, set<string>> preAns;
    for (auto x : m)
    {
        int accNo = x.second;
        string mail = x.first;
        accNo = findParent(parent, accNo);
        preAns[accNo].insert(mail);
    }

    vector<vector<string>> ans;
    for (auto x : preAns)
    {
        auto accNo = x.first;
        auto st = x.second;

        vector<string> temp;
        temp.push_back(accounts[accNo][0]); // Name
        for (auto x : st)
            temp.push_back(x);
        ans.push_back(temp);
    }

    return ans;
}

int main()
{
    //

    return 0;
}