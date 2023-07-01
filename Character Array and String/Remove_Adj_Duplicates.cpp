#include<bits/stdc++.h>
using namespace std;

string RemoveAdjacentDuplicates(string s)
{
    string ans;
    int n = s.length();

    for(int i = 0; i < n; i++)
    {
        int current = s[i];

        if(ans[ans.length()-1] == current)
        ans.pop_back();
        else
        ans.push_back(current);
    }

    return ans;
}

int main()
{
    string s  = "abbaca";
    string ans = RemoveAdjacentDuplicates(s);
    cout << ans << endl;
    return 0;
}