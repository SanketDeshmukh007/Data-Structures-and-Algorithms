#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
    int size;
    int *arr;
    int front;
    int rear;

public:
    MyCircularQueue(int k)
    {
        this->size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool enQueue(int value)
    {
        // Check for overflow
        if ((front == 0 and rear == size - 1) or (front - 1 == rear))
            return false;
        // if first element
        else if (front == -1 and rear == -1)
        {
            front = rear = 0;
            arr[rear] = value;
        }
        // if there is place available at starting
        else if (front != 0 and rear == size - 1)
        {
            rear = 0;
            arr[rear] = value;
        }
        else
        {
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    bool deQueue()
    {
        // Check for underflow
        if (front == -1 and rear == -1)
            return false;
        // if only one element
        else if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;
        else
        {
            arr[front] = -1;
            front++;
        }
        return true;
    }

    int Front()
    {
        if (front == -1 and rear == -1)
            return -1;
        else
            return arr[front];
    }

    int Rear()
    {
        if (front == -1 and rear == -1)
            return -1;
        else
            return arr[rear];
    }

    bool isEmpty()
    {
        if (front == -1 and rear == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if ((front == 0 and rear == size - 1) or (front - 1 == rear))
            return true;
        else
            return false;
    }
};

int main()
{
    MyCircularQueue circularQueue(5); // Creating a circular queue of size 5

    cout << "Is empty: " << circularQueue.isEmpty() << endl; // Should print 1 (true)

    circularQueue.enQueue(1);
    circularQueue.enQueue(2);
    circularQueue.enQueue(3);

    cout << "Front: " << circularQueue.Front() << endl; // Should print 1
    cout << "Rear: " << circularQueue.Rear() << endl;   // Should print 3

    cout << "Is empty: " << circularQueue.isEmpty() << endl; // Should print 0 (false)
    cout << "Is full: " << circularQueue.isFull() << endl;   // Should print 0 (false)

    circularQueue.deQueue();

    cout << "Front after dequeue: " << circularQueue.Front() << endl; // Should print 2

    circularQueue.enQueue(4);
    circularQueue.enQueue(5);

    cout << "Is full: " << circularQueue.isFull() << endl; // Should print 1 (true)

    circularQueue.deQueue();
    circularQueue.deQueue();
    circularQueue.deQueue();
    circularQueue.deQueue();

    cout << "Is empty: " << circularQueue.isEmpty() << endl; // Should print 1 (true)

    return 0;
}