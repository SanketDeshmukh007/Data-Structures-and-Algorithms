#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node*makeUnion(struct Node *head1, struct Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    Node *temp = head1;
    set<int> ans;

    while (temp != 0)
    {
        ans.insert(temp->data);
        temp = temp->next;
    }

    temp = head2;
    while (temp != 0)
    {
        ans.insert(temp->data);
        temp = temp->next;
    }

    vector<int> ans1;
    for (auto x : ans)
        ans1.push_back(x);

    sort(ans1.begin(), ans1.end());

    for (auto x : ans1)
    {
        Node *newnode = new Node(x);
        if (head == 0)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
    }
    return head;
}

int main()
{
    //

    return 0;
}