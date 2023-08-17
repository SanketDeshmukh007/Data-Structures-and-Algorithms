#include<bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int front;
    int rear;

    public:

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int ele)
    {
        // Check for overflow
        if(rear == size)
        {
            cout << "Overflow" << endl;
            return;
        }
        else
        {
            arr[rear] = ele;
            rear++;
        }
    }

    void pop()
    {
        // Check for underflow
        if(front == rear)
        {
            cout << "Underflow" << endl;
            return;
        }
        else
        {
            arr[front] = -1;
            front++;

            if(front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront()
    {
        if(front == rear)
        return -1;
        else
        return arr[front];
    }

    bool empty()
    {
        if(front == rear) return true;
        else return false;
    }

    int getSize()
    {
        if(front == rear) return 0;
        else return rear - front;
    }
};

int main()
{
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << q.getFront() << endl;
    cout << q.getSize() << endl;
    cout << q.empty() << endl;

    q.pop();
    cout << q.getFront() << endl;
    cout << q.getSize() << endl;
    cout << q.empty() << endl;

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout << q.getFront() << endl;
    cout << q.getSize() << endl;
    cout << q.empty() << endl;

    return 0;
}