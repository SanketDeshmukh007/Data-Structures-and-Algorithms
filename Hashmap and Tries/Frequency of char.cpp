#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s = "Thiruvanantapuram";

    unordered_map<char,int> m;

    for(int i = 0; i < int(s.length()); i++)
    {
        m[s[i]]++;
    }

    for(auto x : m)
    cout << x.first << " " << x.second << endl;

    return 0;
}