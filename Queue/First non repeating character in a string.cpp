#include <bits/stdc++.h>
using namespace std;

// First Approach : Using queue takes More time than second
int firstUniqChar(string s)
{
    unordered_map<char, int> m;
    queue<int> q;

    for (int i = 0; i < int(s.length()); i++)
    {
        char ch = s[i];

        m[ch]++;
        q.push(i);

        while (!q.empty())
        {
            if (m[s[q.front()]] > 1)
                q.pop();
            else
                break;
        }
    }

    if (q.empty())
        return -1;
    else
        return q.front();
}

// Second Approach : Using map
int firstUniqChar1(string s)
{
    unordered_map<char, int> m;

    for (auto ch : s)
    {
        m[ch]++;
    }

    for (int i = 0; i < int(s.length()); i++)
    {
        char ch = s[i];
        if (m[ch] == 1)
            return i;
    }
    return -1;
}

int main()
{
    cout << firstUniqChar("leetcode") << endl;
    cout << firstUniqChar1("leetcode") << endl;

    return 0;
}