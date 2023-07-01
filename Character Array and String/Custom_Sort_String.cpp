#include <bits/stdc++.h>
using namespace std;

string customSortString(string order, string s)
{
    string ans;

    int n = order.length();
    for (int i = 0; i < n; i++)
    {
        char ch = order[i];
        while (s.find(ch) != string::npos)
        {
            ans.push_back(ch);
            int index = s.find(ch);
            s.erase(index, 1);
        }
    }
    for (auto x : s)
        ans.push_back(x);

    return ans;
}

int main()
{
    string order = "cba", s = "abcd";
    cout << customSortString(order,s) << endl;

    return 0;
}