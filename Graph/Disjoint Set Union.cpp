#include<bits/stdc++.h>
using namespace std;

const int n = 1e5 + 6;
vector<int> parent(n);
vector<int> Size(n);

void makeSet(int v)
{
    parent[v] = v;
    Size[v] = 1;
}

int findSet(int v)
{
    if(v == parent[v])
    return v;

    return parent[v] = findSet(parent[v]);
}

void unionSets(int a,int b)
{
    a = findSet(a);
    b = findSet(b);

    if(a != b)
    {
        if(Size[a] < Size[b]) 
            swap(a,b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}

int main()
{
    for(int i = 0; i < n; i++)
    {
        makeSet(i);
    }

    return 0;
}