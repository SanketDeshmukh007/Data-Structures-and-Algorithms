#include <bits/stdc++.h>
using namespace std;

string reverseOnlyLetters(string s)
{
    int st = 0;
    int end = s.length() - 1;

    if (st == end)
        return s;

    while (st <= end)
    {
        if (isalpha(s[st]) && isalpha(s[end]))
        {
            swap(s[st], s[end]);
            st++;
            end--;
        }
        if (isalpha(s[st]) == false)
            st++;
        if (isalpha(s[end]) == false)
            end--;
    }
    return s;
}

int main()
{
    string s = "Test1ng-Leet=code-Q!";
    string ans = reverseOnlyLetters(s);
    cout << ans << endl;

    return 0;
}