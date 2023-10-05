#include<bits/stdc++.h>
using namespace std;


int main()
{
    // Creation
    unordered_map<string,int> m;

    // Insertion
    pair<string,int> p = make_pair("Scorpio",1);
    m.insert(p);

    pair<string,int> p1("Alto",2);
    m.insert(p1);

    m.insert({"Thar",3});

    m["Fortuner"] = 4;

    // Access
    cout << m.at("Scorpio") << endl;
    // cout << m.at("alto") << endl;
    cout << m.at("Alto") << endl;
    cout << m["Fortuner"] << endl;

    // Search
    cout << m.count("Alto") << endl;

    // Iterator
    if(m.find("Fortuner") != m.end())
    cout << "Fortuner Found" << endl;
    else cout << "Fortuner Not Found" << endl;

    cout << m.size() << endl;
    cout << m["Swift"] << endl;
    cout << m.size() << endl;

    cout << "Printing Map" << endl;
    for(auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}