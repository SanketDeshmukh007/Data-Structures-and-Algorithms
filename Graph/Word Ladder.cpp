#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    queue<string> q;
    q.push(beginWord);
    int wordSize = beginWord.size();

    // For doing operation in O(1)
    unordered_set<string> word;
    for (int i = 0; i < wordList.size(); i++)
    {
        word.insert(wordList[i]);
    }

    if (word.find(endWord) == word.end())
        return 0;

    int len = 0;
    while (!q.empty())
    {
        len++;
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            string s = q.front();
            q.pop();

            for (int j = 0; j < wordSize; j++)
            {
                char original_Character = s[j];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    s[j] = ch;

                    if (s == endWord)
                        return len + 1;

                    if (word.find(s) == word.end())
                        continue;

                    word.erase(s);
                    q.push(s);
                }

                s[j] = original_Character;
            }
        }
    }

    return 0;
}

int main()
{
    //

    return 0;
}