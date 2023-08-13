#include<bits/stdc++.h>
using namespace std;

vector<int> previousSmallerElement(vector<int> v)
{
    int n = v.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

    for(int i = 0; i < n; i++)
    {
        int curr = v[i];

        while(s.top() >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main()
{
    vector<int> v = {2,1,4,3};

    vector<int> ans = previousSmallerElement(v);

    for(auto x : ans)
    cout << x << " ";

    return 0;
}