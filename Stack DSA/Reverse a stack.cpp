#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& s,int element)
{
    if(s.empty())
    {
        s.push(element);
        return;
    }

    int temp = s.top();
    s.pop();
    insertAtBottom(s,element);
    s.push(temp);
}

void reverseStack(stack<int>& s)
{
    // Base Case
    if(s.empty()) return;

    int element = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s,element);
}

void print(stack<int> s)
{
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl << endl;
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    print(s);

    reverseStack(s);
    
    print(s);

    return 0;
}