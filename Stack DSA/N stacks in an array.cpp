#include <bits/stdc++.h>
using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;

    int freespot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        arr = new int[S];
        top = new int[N];
        next = new int[S];

        for (int i = 0; i < N; i++)
        {
            top[i] = -1;
        }

        for (int i = 0; i < S; i++)
        {
            next[i] = i + 1;
        }
        next[S - 1] = -1;

        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Check for stack Overflow
        if (freespot == -1)
            return false;

        // Find index for inserting element
        int index = freespot;

        // Update freespot
        freespot = next[index];

        // Insert element
        arr[index] = x;

        // Update next[]
        next[index] = top[m - 1];

        // Update top[]
        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Check for Underflow
        if (top[m - 1] == -1)
            return -1;

        // Find index
        int index = top[m - 1];

        // Update top[]
        top[m - 1] = next[index];

        // Update next[]
        next[index] = freespot;

        // Update freespot
        freespot = index;

        return arr[index];
    }
};
int main()
{
    int N = 3;  // Number of stacks
    int S = 10; // Total size of the array

    NStack nStack(N, S);

    nStack.push(5, 1);
    nStack.push(10, 2);
    nStack.push(15, 3);

    cout << "Popped from stack 1: " << nStack.pop(1) << endl;
    cout << "Popped from stack 2: " << nStack.pop(2) << endl;
    cout << "Popped from stack 3: " << nStack.pop(3) << endl;

    return 0;
}