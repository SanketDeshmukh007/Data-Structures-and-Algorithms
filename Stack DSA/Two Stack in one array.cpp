#include <bits/stdc++.h>
using namespace std;

class TwoStack
{
    int size;
    int top1;
    int top2;
    int *arr;

public:
    // Initialize TwoStack.
    TwoStack(int s)
    {
        arr = new int[s];
        this->size = s;
        top1 = -1;
        top2 = size;
    }

    // Push in stack 1.
    void push1(int num)
    {

        if (top2 - top1 != 1)
        {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {

        if (top2 - top1 != 1)
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if (top1 == -1)
            return -1;
        else
        {
            int ele = arr[top1];
            top1--;
            return ele;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        if (top2 == size)
            return -1;
        else
        {
            int ele = arr[top2];
            top2++;
            return ele;
        }
    }
};

int main()
{
    int stackSize = 10; // Set the size of the stack

    TwoStack twoStacks(stackSize); // Create an instance of the TwoStack class

    // Push elements into the two stacks
    twoStacks.push1(5);
    twoStacks.push1(10);
    twoStacks.push2(20);
    twoStacks.push2(30);

    // Pop elements from the two stacks
    cout << "Popped from stack 1: " << twoStacks.pop1() << endl;
    cout << "Popped from stack 2: " << twoStacks.pop2() << endl;
    cout << "Popped from stack 1: " << twoStacks.pop1() << endl;
    cout << "Popped from stack 2: " << twoStacks.pop2() << endl;

    return 0;
}
