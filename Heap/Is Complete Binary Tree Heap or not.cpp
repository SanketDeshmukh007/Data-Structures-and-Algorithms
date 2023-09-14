#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

pair<bool, int> solve(struct Node *tree)
{
    if (tree == 0)
        return {true, INT_MIN};
    if (tree->left == 0 and tree->right == 0)
        return {true, tree->data};

    pair<bool, int> l = solve(tree->left);
    pair<bool, int> r = solve(tree->right);

    if ((l.first == true and r.first == true) and (tree->data > l.second and tree->data > r.second))
        return {true, tree->data};
    else
        return {false, tree->data};
}
bool isHeap(struct Node *tree)
{
    // bool ans = true;
    pair<bool, int> ans = solve(tree);
    return ans.first;
}

int main()
{
    //

    return 0;
}