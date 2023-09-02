#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *sortedListToBST(ListNode *head)
{
    if (head == 0)
        return NULL;
    if (head->next == 0)
        return new TreeNode(head->val);

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = NULL;
    while (fast != 0)
    {
        fast = fast->next;
        if (fast != 0)
        {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
    }

    prev->next = NULL;

    TreeNode *root = new TreeNode(slow->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);

    return root;
}

void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    // Create a sorted linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Convert sorted linked list to BST
    TreeNode *root = sortedListToBST(head);

    // Print the inorder traversal of the BST
    inorderTraversal(root);

    return 0;
}