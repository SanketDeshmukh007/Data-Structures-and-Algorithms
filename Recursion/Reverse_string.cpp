#include<bits/stdc++.h>
using namespace std;

void Reverse(string& s,int start,int end)
{
    // 1. Base Case
    if(start > end)
    return;

    // 2. Procssing
    swap(s[start],s[end]);

    // 3. Recursive Relation
    Reverse(s,start+1,end-1);
}

int main()
{
    string s = "sanket";
    Reverse(s,0,s.length()-1);
    cout << s << endl;

    return 0;
}