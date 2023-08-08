#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != NULL)
    {
        cout << current->val;
        if (current->next != NULL)
        {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

vector<int> nodesBetweenCriticalPoints(ListNode *head)
{

    vector<int> ans = {-1, -1};
    if (head == 0)
        return ans;

    vector<int> index;
    ListNode *curr = head->next;
    ListNode *prev = head;
    int i = 2;
    while (curr != 0 and curr->next != 0)
    {
        if (curr->val > prev->val and curr->val > curr->next->val)
            index.push_back(i);

        if (curr->val < prev->val and curr->val < curr->next->val)
            index.push_back(i);

        prev = curr;
        curr = curr->next;
        i++;
    }

    if (index.size() == 0 or index.size() == 1)
        return ans;

    int mini = INT_MAX;
    int maxi = index[index.size() - 1] - index[0];
    for (int i = 0; i < int(index.size()) - 1; i++)
    {
        mini = min(mini, index[i + 1] - index[i]);
    }

    ans[0] = mini;
    ans[1] = maxi;

    return ans;
}

int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(5);
    head->next->next = new ListNode(8);
    head->next->next->next = new ListNode(6);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next = new ListNode(2);

    printLinkedList(head);

    vector<int> result = nodesBetweenCriticalPoints(head);

    cout << "Minimum distance: " << result[0] << ", Maximum distance: " << result[1] << endl;

    // Don't forget to free the allocated memory
    ListNode *current = head;
    while (current != NULL)
    {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
