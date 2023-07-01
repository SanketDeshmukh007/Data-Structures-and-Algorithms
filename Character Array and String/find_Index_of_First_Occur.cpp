#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    int index = -1;
    if (haystack.find(needle) != string::npos)
        index = haystack.find(needle);

    return index;
}

int main()
{
    string haystack = "sadbutsad", needle = "sad";
    int ans = strStr(haystack,needle);
    cout << ans << endl;

    return 0;
}