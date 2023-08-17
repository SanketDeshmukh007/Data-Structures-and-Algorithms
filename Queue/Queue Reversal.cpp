#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Using Stack
queue<int> rev(queue<int> q)
{
    stack<int> s;

    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        s.push(ele);
    }

    while (!s.empty())
    {
        int ele = s.top();
        s.pop();
        q.push(ele);
    }
    return q;
}

// Approach 2 : Using Recursion
void rev1(queue<int>& q)
{
    if(q.empty()) return;

    int temp = q.front();
    q.pop();
    rev1(q);
    q.push(temp);
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    queue<int> ans = rev(q);
    cout << "Reversed Queue: " << endl;
    while(!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl << endl;

    cout << "Using Recursion" << endl;
    rev1(q);
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}