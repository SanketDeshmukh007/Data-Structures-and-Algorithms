#include<bits/stdc++.h>
using namespace std;

void insertSorted(stack<int>& s,int ele)
{
    if(s.empty()) 
    {
        s.push(ele);
        return;
    }

    if(s.top() >= ele)
    {
        s.push(ele);
        return;
    }

    int temp = s.top();
    s.pop();
    insertSorted(s,ele);
    s.push(temp);
}

void sortStack(stack<int> &s)
{
    if(s.empty()) return;

    int ele = s.top();
    s.pop();
    sortStack(s);
    insertSorted(s,ele);
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
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);

    print(s);

    sortStack(s);

    print(s);

    return 0;
}