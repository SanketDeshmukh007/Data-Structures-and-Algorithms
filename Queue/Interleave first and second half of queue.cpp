#include <bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &q)
{
    int n = q.size();

    int k = n / 2;

    queue<int> q1;
    queue<int> q2;

    for (int i = 0; i < k; i++)
    {
        int temp = q.front();
        q.pop();
        q1.push(temp);
    }

    for (int i = 0; i < k; i++)
    {
        int temp = q.front();
        q.pop();
        q2.push(temp);
    }

    while (!q1.empty() and !q2.empty())
    {
        int temp1 = q1.front();
        q1.pop();
        q.push(temp1);

        int temp2 = q2.front();
        q2.pop();
        q.push(temp2);
    }

    // if size is odd
    if(n & 1)
    {
        int temp = q.front(); q.pop();
        q.push(temp);
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    // q.push(80);

    interLeaveQueue(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}