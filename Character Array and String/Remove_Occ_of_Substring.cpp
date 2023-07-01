#include<bits/stdc++.h>
using namespace std;

string RemoveOccurences(string s, string part)
{
    while(s.find(part) != string::npos)
    {
        int index = s.find(part);
        s.erase(index,part.length());
    }
    return s;
}

int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    string ans = RemoveOccurences(s,part);
    cout << ans << endl;
    return 0;
}