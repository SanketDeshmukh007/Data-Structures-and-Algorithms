#include <bits/stdc++.h>
using namespace std;

void permutations(string &s, int i, vector<string> &ans)
{
    // Base Case
    if (i >= int(s.length()))
    {
        ans.push_back(s);
        return;
    }

    // Swapping
    for (int j = i; j < int(s.length()); j++)
    {
        swap(s[i], s[j]);

        permutations(s, i + 1, ans);

        swap(s[i], s[j]);
    }
}

bool checkInclusion(string s1, string s2)
{
    vector<string> ans;
    int i = 0;
    permutations(s1, i, ans);

    for (auto x : ans)
    {
        if (s2.find(x) != string::npos)
            return true;
    }
    return false;
}

int main()
{
    string s1 = "ab" , s2 = "eidbaooo";

    cout << checkInclusion(s1,s2) << endl;

    return 0;
}