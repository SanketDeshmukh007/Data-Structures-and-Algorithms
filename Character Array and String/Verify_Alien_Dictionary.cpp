#include<bits/stdc++.h>
using namespace std;

bool correctOrder(unordered_map<char,int> &m,string a,string b)
{
    int n = min(a.length(),b.length());
    int i = 0;

    while(i < n)
    {
        if(m[a[i]] > m[b[i]])
        return false;
        else if(m[a[i]] < m[b[i]])
        return true;

        i++;
    }

    if(a.length() > b.length() and a.find(b) != string::npos)
    {
        return false;
    }

    return true;
}

bool isAlienSorted(vector<string>& words, string order)
{
    unordered_map<char,int> m;

    for(int i = 0; i < int(order.length());i++)
    {
        char ch = order[i];
        m[ch] = i;
    }

    for(int i = 0; i < int(words.size()-1); i++)
    {
        if(!correctOrder(m,words[i],words[i+1]))
        return false;
    }
    return true;
}

int main()
{
    vector<string> words = {"apple","app"};
    string order = "abcdefghijklmnopqrstuvwxyz";
    // false;
    // vector<string> words = {"word","world","row"};
    // string order = "worldabcefghijkmnpqstuvxyz";
    // false;

    cout << isAlienSorted(words,order) << endl;

    return 0;
}