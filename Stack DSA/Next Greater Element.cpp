#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int length(ListNode *head)
{
    int count = 0;
    ListNode *temp = head;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

vector<int> nextLargerNodes(ListNode *head)
{
    int n = length(head);
    vector<int> ans(n);
    vector<int> arr(n);
    ListNode *temp = head;

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp->val;
        temp = temp->next;
    }

    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (!s.empty() && s.top() <= curr)
        {
            s.pop();
        }

        if (s.empty())
            ans[i] = 0;
        else
            ans[i] = s.top();

        s.push(curr);
    }
    return ans;
}

int main()
{
    // Creating the linked list: 2 -> 7 -> 4 -> 3 -> 5
    ListNode *head = new ListNode(2);
    head->next = new ListNode(7);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    // Calling the function and printing the result
    vector<int> result = nextLargerNodes(head);

    cout << "Original List: 2 -> 7 -> 4 -> 3 -> 5" << endl;
    cout << "Next Larger Nodes: ";
    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}
