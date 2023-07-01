#include <bits/stdc++.h>
using namespace std;

bool canFormByDeleting(string word, string str)
{
    int i = 0, j = 0;

    while (i < int(word.size()) && j < int(str.size()))
    {

        if (word[i] == str[j])
            i++;

        j++;
    }

    return i == int(word.size());
}

string findLongestWord(string s, vector<string> &d)
{
    string res = "";

    for (auto str : d)
    {

        if (canFormByDeleting(str, s))
        {

            if (str.size() > res.size() || (str.size() == res.size() && str < res))
                res = str;
        }
    }

    return res;
}

int main()
{
    string s = "abpcplea";
    vector<string> dictionary = {"ale","apple","monkey","plea"};
    cout << findLongestWord(s,dictionary) << endl;

    return 0;
}