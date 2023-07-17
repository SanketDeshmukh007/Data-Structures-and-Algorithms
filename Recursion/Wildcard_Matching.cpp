#include <bits/stdc++.h>
using namespace std;

bool Match(string &s, int i, string &p, int j)
{
    // Base Case
    if (i == int(s.length()) and j == int(p.length()))
        return true;

    if (i == int(s.length()) and j < int(p.length()))
    {
        while (j < int(p.length()))
        {
            if (p[j] != '*')
                return false;

            j++;
        }
        return true;
    }

    // Single character matching
    if (s[i] == p[j] || p[j] == '?')
    {
        // Matched
        return Match(s, i + 1, p, j + 1);
    }

    if (p[j] == '*')
    {
        // case 1 --> treat * as empty
        bool case1 = Match(s, i, p, j + 1);
        // case 2 --> let * consume one character
        bool case2 = Match(s, i + 1, p, j);

        return case1 || case2;
    }

    // character doesnt match
    return false;
}

bool isMatch(string s, string p)
{
    int i = 0; // pointer index for string s
    int j = 0; // pointer index for string p

    return Match(s, i, p, j);
}

int main()
{
    if(isMatch("abcdefg","ab*fg"))
    cout << "Matched" << endl;
    else cout << "Not Matched" << endl;

    return 0;
}