#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middle(ListNode *&head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != 0)
    {
        fast = fast->next;
        if (fast != 0)
        {
            fast = fast->next;

            slow = slow->next;
        }
    }
    return slow;
}

ListNode *reverse(ListNode *&Node)
{
    ListNode *prev = NULL;
    ListNode *curr = Node;

    while (curr != NULL)
    {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{

    if (head == 0 or head->next == 0)
        return true;

    ListNode *mid = middle(head);
    mid->next = reverse(mid->next);
    ListNode *i = head;
    ListNode *j = mid->next;

    while (j != 0)
    {
        if (i->val != j->val)
            return false;

        i = i->next;
        j = j->next;
    }
    return true;
}

void print(ListNode *&head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl
         << endl;
}

int main()
{
    // Create the linked list with values 1, 2, 3, 4, and 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(1);

    // Print the linked list to verify it's created correctly
    print(head);

    bool ans = isPalindrome(head);
    cout << ans << endl;

    // Don't forget to delete the nodes to free memory
    ListNode *temp = head;
    while (temp != nullptr)
    {
        ListNode *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}