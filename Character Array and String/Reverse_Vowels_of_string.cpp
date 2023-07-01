#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch)
{
    ch = tolower(ch);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;

    return false;
}

string reverseVowels(string s)
{
    int st = 0;
    int e = s.length() - 1;
    while (st <= e)
    {
        if (isVowel(s[st]) && isVowel(s[e]))
        {
            swap(s[st], s[e]);
            st++;
            e--;
        }
        else if (isVowel(s[st]) == false)
            st++;
        else
            e--;
    }
    return s;
}

int main()
{
    string s = "leetcode";
    string ans = reverseVowels(s);
    cout << ans << endl;

    return 0;
}