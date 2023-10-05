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

bool searchWord(Node *root, string word)
{
    // Base Case
    if (word.length() == 0)
        return root->isTerminal;

    char ch = word[0];
    int index = ch - 'a';
    Node *child;

    if (root->children[index] != NULL)
        child = root->children[index];
    else
        return false;

    return searchWord(child, word.substr(1));
}

void deleteWord(Node *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = false;
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
        return;

    deleteWord(child, word.substr(1));
}

bool startsWith(Node *root, string word)
{
    if (word.length() == 0)
    {
        return true;
    }

    char ch = word[0];
    int index = ch - 'a';
    Node *child;

    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
        return false;

    return startsWith(child, word.substr(1));
}

int main()
{
    Node *root = new Node('-');

    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "baba");
    insertWord(root, "baby");
    insertWord(root, "babbar");

    cout << "Searching" << endl;
    if (searchWord(root, "baby"))
        cout << "Present" << endl;
    else
        cout << "Absent" << endl;

    cout << "Deleting" << endl;
    deleteWord(root, "baby");
    if (searchWord(root, "baby"))
        cout << "Present" << endl;
    else
        cout << "Absent" << endl;

    return 0;
}