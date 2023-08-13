#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s,int ele)
{
    if(s.size() == 0)
    {
        s.push(ele);
        return;
    }

    int temp = s.top();
    s.pop();
    insertAtBottom(s,ele);
    s.push(temp);
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(15);
    s.push(27);
    s.push(32);
    s.push(11);
    // s.push(60);
    // s.push(70);
    // s.push(80);
    int ele = s.top();
    s.pop();
    insertAtBottom(s,ele);
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}