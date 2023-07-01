#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{

    int freqS[26] = {0};
    int freqT[26] = {0};

    for (char ch : s)
        freqS[ch - 'a']++;
    for (char ch : t)
        freqT[ch - 'a']++;

    for (int i = 0; i < 26; i++)
    {
        if (freqS[i] != freqT[i])
            return false;
    }
    return true;
}

int main()
{
    string s = "anagram", t = "nagaram";
    bool ans = isAnagram(s, t);
    if (ans)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}