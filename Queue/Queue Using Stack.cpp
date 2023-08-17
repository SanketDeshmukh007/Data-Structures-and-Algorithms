#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> input;
    stack<int> output;

    MyQueue()
    {
    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        if (!output.empty())
        {
            int ele = output.top();
            output.pop();
            return ele;
        }
        else
        {
            while (!input.empty())
            {
                int ele = input.top();
                input.pop();
                output.push(ele);
            }

            int ele = output.top();
            output.pop();
            return ele;
        }
    }

    int peek()
    {
        if (!output.empty())
        {
            return output.top();
        }
        else
        {
            while (!input.empty())
            {
                int ele = input.top();
                input.pop();
                output.push(ele);
            }

            return output.top();
        }
    }

    bool empty()
    {
        if (input.empty() and output.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    MyQueue myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    cout << "Front element: " << myQueue.peek() << endl;
    cout << "Removed element: " << myQueue.pop() << endl;
    cout << "Is the queue empty? " << (myQueue.empty() ? "Yes" : "No") << endl;

    myQueue.push(4);
    myQueue.push(5);

    cout << "Front element: " << myQueue.peek() << endl;
    cout << "Removed element: " << myQueue.pop() << endl;
    cout << "Is the queue empty? " << (myQueue.empty() ? "Yes" : "No") << endl;

    return 0;
}