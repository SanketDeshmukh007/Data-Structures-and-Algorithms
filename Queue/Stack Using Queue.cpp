#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
public:
    queue<int> q;

    MyStack()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

    void push(int x)
    {
        q.push(x);
        int size = q.size();
        while (size > 1)
        {
            int ele = q.front();
            q.pop();
            q.push(ele);
            size--;
        }
    }

    int pop()
    {
        int ele = q.front();
        q.pop();
        return ele;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Top element: " << myStack.top() << endl;
    cout << "Popped element: " << myStack.pop() << endl;
    cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl;

    myStack.push(4);
    myStack.push(5);

    cout << "Top element: " << myStack.top() << endl;
    cout << "Popped element: " << myStack.pop() << endl;
    cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl;

    return 0;
}
