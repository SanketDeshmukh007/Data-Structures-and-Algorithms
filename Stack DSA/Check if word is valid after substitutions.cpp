#include <bits/stdc++.h>
using namespace std;

bool isValid(string st)
{
    if (st[0] != 'a')
        return false;

    stack<char> s;

    for (auto ch : st)
    {
        if (ch == 'a')
            s.push('a');
        else if (ch == 'b')
        {
            if (!s.empty() and s.top() == 'a')
                s.push('b');
            else
                return false;
        }
        else
        {
            if (!s.empty() and s.top() == 'b')
            {
                s.pop();
                if (!s.empty() and s.top() == 'a')
                    s.pop();
                else
                    return false;
            }
            else
                return false;
        }
    }

    return s.empty();
}

int main()
{
    if(isValid("abcabcababcc")) // "abccba"
    cout << "Valid" << endl;
    else cout << "Not Valid" << endl;

    return 0;
}