#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{
    unordered_map<char, int> m;
    int n = A.length();
    queue<char> q;
    string ans;

    for (int i = 0; i < n; i++)
    {
        char ch = A[i];

        m[ch]++;
        q.push(ch);

        while (!q.empty())
        {
            if (m[q.front()] > 1)
                q.pop();
            else
            {
                ans.push_back(q.front());
                break;
            }
        }

        if (q.empty())
            ans.push_back('#');
    }
    return ans;
}

int main()
{
    cout << FirstNonRepeating("aabc") << endl;

    return 0;
}