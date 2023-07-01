#include <bits/stdc++.h>
using namespace std;

int expandAroundIndex(string s, int i, int j)
{
    int count = 0;
    // jab tak match karega count++ kardo and i piche and j aage kardo
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        count++;
        i--;
        j++;
    }
    return count;
}

int countSubstrings(string s)
{

    int totalCount = 0;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        // Odd Substrings
        int oddAns = expandAroundIndex(s, i, i);
        totalCount = totalCount + oddAns;
        // Even SubStrings
        int evenAns = expandAroundIndex(s, i, i + 1);
        totalCount = totalCount + evenAns;
    }
    return totalCount;
}

int main()
{
    string s = "abc";
    int ans = countSubstrings(s);
    cout << ans << endl;

    return 0;
}