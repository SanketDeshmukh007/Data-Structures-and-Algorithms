#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Using Recursion
void sol(queue<int> &q, int i, int k)
{
    if (i == k)
        return;

    int temp = q.front();
    q.pop();
    i++;
    sol(q, i, k);
    q.push(temp);
}

queue<int> modifyQueue(queue<int> q, int k)
{
    sol(q, 0, k);
    int n = q.size() - k;
    for (int i = 0; i < n; i++)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
    return q;
}

// Approach 2 : Using stack
void modify(queue<int>& q,int k)
{
    stack<int> s;
    for(int i = 0; i < k; i++)
    {
        int temp = q.front();
        q.pop();
        s.push(temp);
    }

    while(!s.empty())
    {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    int n = q.size() - k;
    for(int i = 0; i < n; i++)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

}

int main()
{
    int k = 3;
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    q.push(15);

    queue<int> modifiedQueue = modifyQueue(q, k);

    cout << "Queue after modifying: ";
    while (!modifiedQueue.empty())
    {
        cout << modifiedQueue.front() << " ";
        modifiedQueue.pop();
    }
    cout << endl << endl;

    cout << "Using Stack" << endl;
    modify(q,k);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
