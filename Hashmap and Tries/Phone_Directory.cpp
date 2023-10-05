#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *children[26]; // array
    bool isTerminal;

    Node(char d)
    {
        data = d;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
    }
};

void insertWord(Node *root, string word)
{
    // Base Case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    Node *child;

    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        child = new Node(ch);
        root->children[index] = child;
    }

    insertWord(child, word.substr(1));
}

void printSuggestions(Node *curr, vector<string> &temp, string prefix)
{
    if (curr->isTerminal)
    {
        temp.push_back(prefix);
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        Node *next = curr->children[ch - 'a'];

        if (next != 0)
        {
            prefix.push_back(ch);
            printSuggestions(next, temp, prefix);
            prefix.pop_back();
        }
    }
}

vector<vector<string>> getSuggestions(Node *root, string input)
{
    vector<vector<string>> ans;
    Node *prev = root;
    string prefix = "";

    for (int i = 0; i < int(input.length()); i++)
    {
        char ch = input[i];
        prefix.push_back(ch);
        int index = ch - 'a';

        Node *curr = prev->children[index];

        if (curr == 0)
            break;

        vector<string> temp;
        printSuggestions(curr, temp, prefix);
        ans.push_back(temp);
        temp.clear();
        prev = curr;
    }
    return ans;
}

vector<vector<string>> phoneDirectory(vector<string> v, string &input)
{
    Node *root = new Node('-');

    for (auto x : v)
        insertWord(root, x);

    return getSuggestions(root, input);
}

int main()
{
    vector<string> v = {"cod", "coding", "codding", "code", "coly"};
    // {"lover","lane","lost","lend","loving","love","lord","least","last","list","live"};
    sort(v.begin(), v.end());
    string input = "coding";
    // "lovi";

    vector<vector<string>> ans = phoneDirectory(v, input);

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}