#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    vector<pair<int, int>> s;

public:
    MinStack()
    {
        // Constructor if needed
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.push_back({val, val});
        }
        else
        {
            pair<int, int> p;
            p.first = val;
            p.second = min(s.back().second, val);
            s.push_back(p);
        }
    }

    void pop()
    {
        if (!s.empty())
            s.pop_back();
    }

    int top()
    {
        if (!s.empty())
            return s.back().first;

        return -1; // Indicate empty stack
    }

    int getMin()
    {
        if (!s.empty())
            return s.back().second;

        return -1; // Indicate empty stack
    }
};

int main()
{
    MinStack minStack;

    minStack.push(3);
    minStack.push(5);
    minStack.push(2);

    cout << "Top element: " << minStack.top() << endl;        // Output: 2
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 2

    minStack.pop();
    cout << "Top element after pop: " << minStack.top() << endl;        // Output: 5
    cout << "Minimum element after pop: " << minStack.getMin() << endl; // Output: 3

    return 0;
}
