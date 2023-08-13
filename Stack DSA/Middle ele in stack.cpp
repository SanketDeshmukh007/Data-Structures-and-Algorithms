#include<bits/stdc++.h>
using namespace std;

int findMiddle(stack<int> &s,int size)
{
    // Base Case
    if(s.size() == 0)
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }

    if(int(s.size()) == size)
    return s.top();

    int temp = s.top();
    s.pop();
    return findMiddle(s,size);
    s.push(temp);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // s.push(60);
    // s.push(70);
    // s.push(80);

    int totalSize = s.size();
    int size;
    if(totalSize % 2 == 0)
    size = totalSize / 2;
    else
    size = (totalSize / 2) + 1;

    int middle = findMiddle(s,size);
    cout << "Middle element is: " << middle << endl;

    return 0;
}