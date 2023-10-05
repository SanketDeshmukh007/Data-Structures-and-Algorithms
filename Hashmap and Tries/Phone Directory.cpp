#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> getSuggestions(string input,vector<string> v)
{
    vector<vector<string>> ans;
    
    string part;
    for(int i = 0; i < int(input.length()); i++)
    {
        part.push_back(input[i]);
        // cout << part << endl;
        vector<string> temp;
        for(auto y : v)
        {
            if(y.find(part) != string::npos)
                temp.push_back(y);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
        vector<string> v = {"cod", "coding", "codding", "code", "coly"};
    // {"lover","lane","lost","lend","loving","love","lord","least","last","list","live"};
    sort(v.begin(),v.end());
    string input = "coding";
    // "lovi";

    vector<vector<string>> ans = getSuggestions(input,v);

    for(auto x : ans)
    {
        for(auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}