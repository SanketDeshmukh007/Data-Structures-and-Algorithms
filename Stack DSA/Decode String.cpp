#include <bits/stdc++.h>
using namespace std;

string decodeString(string st)
{
    string ans = "";
    stack<char> s;

    for (auto ch : st)
    {
        string temp1 = ""; // to store string
        string temp2 = ""; // to store numbers

        if (ch != ']')
            s.push(ch);
        else
        {
            while (!s.empty() and (s.top() >= 'a' and s.top() <= 'z'))
            {
                temp1 += s.top();
                s.pop();
            }
            s.pop(); // Opening Bracket

            reverse(temp1.begin(), temp1.end());

            while (!s.empty() and (s.top() >= '0' and s.top() <= '9'))
            {
                temp2 += s.top();
                s.pop();
            }

            reverse(temp2.begin(), temp2.end());
            int num = stoi(temp2);
            temp2 = temp1;

            while (num > 1)
            {
                temp1 += temp2;
                num--;
            }

            for (auto ch : temp1)
            {
                s.push(ch);
            }
        }
    }

    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    cout << decodeString("3[a]2[bc]") << endl;

    return 0;
}