#include<bits/stdc++.h>
using namespace std;

class KQueue
{
    public:
    int n, k, freespot;
    int *arr, *front, *rear, *next;

    KQueue(int n,int k)
    {
        this->n = n;
        this->k = k;
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        freespot = 0;

        for(int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        for(int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n-1] = -1;
    }

    bool push(int x,int m)
    {
        if(freespot == -1)
        {
            cout << "Overflow" << endl;
            return false;
        }

        // find index
        int index = freespot;
        // Update freespot
        freespot = next[index];
        // if first element of queue
        if(front[m-1] == -1)
        front[m-1] = index;
        else
        {
            // link new element with prev rearest element
            next[rear[m-1]] = index;
        }

        // Update next
        next[index] = -1;
        // Update rear
        rear[m-1] = index;
        // Add element
        arr[index] = x;

        return true;
    }

    int pop(int m)
    {
        if(front[m-1] == -1)
        {
            cout << "Underflow" << endl;
            return -1;
        }

        // find index
        int index = front[m-1];
        // Update front
        front[m-1] = next[index];
        // Update next
        next[index] = freespot;
        // Update freespot
        freespot = index;

        return arr[index];
    }

    ~KQueue()
    {
        delete []arr;
        delete []front;
        delete []rear;
        delete []next;
    }
};

int main()
{
    KQueue kq(8,3);
    cout << kq.push(1,1) << endl;
    cout << kq.push(2,1) << endl;
    cout << kq.push(5,2) << endl;
    cout << kq.push(3,1) << endl;
    cout << kq.pop(2) << endl;
    cout << kq.pop(2) << endl;
    cout << kq.pop(1) << endl;

    return 0;
}