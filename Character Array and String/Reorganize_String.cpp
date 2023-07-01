#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s)
{
    int freq[26] = {0};
    for (char ch : s)
        freq[ch - 'a']++;

    char max_freq_char;
    int max_freq = INT_MIN;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > max_freq)
        {
            max_freq_char = i + 'a';
            max_freq = freq[i];
        }
    }

    int index = 0;
    while (max_freq > 0 && index < s.length())
    {
        s[index] = max_freq_char;
        max_freq--;
        index += 2;
    }

    if (max_freq != 0)
        return "";

    freq[max_freq_char - 'a'] = 0;

    for (int i = 0; i < 26; i++)
    {
        while (freq[i] > 0)
        {
            if (index >= s.length())
                index = 1;

            freq[i]--;

            s[index] = i + 'a';
            index += 2;
        }
    }
    return s;
}

int main()
{
    string ans = reorganizeString("aaabc");
    cout << ans << endl;

    return 0;
}