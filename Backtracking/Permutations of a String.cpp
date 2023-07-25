#include<bits/stdc++.h>
using namespace std;

void permutations(string& s,int i)
{
    // Base Case
    if(i >= int(s.length()))
    {
        cout << s << " ";
        return;
    }

    // Swapping
    for(int j = i; j < int(s.length()); j++)
    {
        swap(s[i],s[j]);
        // Recursive Call
        permutations(s,i+1);
        // Backtracking
        swap(s[i],s[j]);
    }
}

int main()
{
    string s = "abc";
    int i = 0;
    permutations(s,i);

    return 0;
}