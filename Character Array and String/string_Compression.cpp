#include <bits/stdc++.h>
using namespace std;

int compress(vector<char> &s)
{
    int index = 0;
    int count = 1;
    char prev = s[0];

    for (int i = 1; i < int(s.size()); i++)
    {
        if (s[i] == prev)
            count++;
        else
        {
            s[index++] = prev;
            int start = index;
            if (count > 1)
            {
                while (count)
                {
                    s[index++] = count % 10 + '0';
                    count = count / 10;
                }
            }
            reverse(s.begin() + start, s.begin() + index);
            prev = s[i];
            count = 1;
        }
    }
    s[index++] = prev;
    int start = index;
    if (count > 1)
    {
        s[index++] = count % 10 + '0';
        count = count / 10;
    }
    reverse(s.begin() + start, s.begin() + index);

    return index;
}

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int len = compress(chars);
    cout << len << endl;

    return 0;
}