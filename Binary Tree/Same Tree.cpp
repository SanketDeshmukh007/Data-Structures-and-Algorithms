#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == 0 or q == 0)
        return p == q;

    return ((p->val == q->val) and isSameTree(p->left, q->left) and isSameTree(p->right, q->right));
}

int main()
{
    TreeNode *tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode *tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    bool result = isSameTree(tree1, tree2);

    if (result)
    {
        cout << "The two trees are structurally identical." << endl;
    }
    else
    {
        cout << "The two trees are not structurally identical." << endl;
    }

    // Clean up memory (not shown in this example, but you should deallocate the nodes)

    return 0;
}
