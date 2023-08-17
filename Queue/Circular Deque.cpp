#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque
{
    int size;
    int *arr;
    int front;
    int rear;

public:
    MyCircularDeque(int k)
    {
        this->size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool insertFront(int value)
    {
        // check for overflow
        if ((front == 0 and rear == size - 1) or (front - 1 == rear))
            return false;
        // if first element
        else if (front == -1 and rear == -1)
        {
            front = rear = 0;
            arr[front] = value;
        }
        // Circular Condition
        else if (front == 0)
        {
            front = size - 1;
            arr[front] = value;
        }
        else
        {
            front--;
            arr[front] = value;
        }
        return true;
    }

    bool insertLast(int value)
    {
        // check for overflow
        if ((front == 0 and rear == size - 1) or (front - 1 == rear))
            return false;
        // if first element
        else if (front == -1 and rear == -1)
        {
            front = rear = 0;
            arr[rear] = value;
        }
        // Circular Condition
        else if (rear == size - 1)
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

    bool deleteFront()
    {
        // check for underflow
        if (front == -1 and rear == -1)
            return false;
        // if one element
        else if (front == rear)
            front = rear = -1;
        // circular condition
        else if (front == size - 1)
            front = 0;
        else
        {
            arr[front] = -1;
            front++;
        }
        return true;
    }

    bool deleteLast()
    {
        // check for underflow
        if (front == -1 and rear == -1)
            return false;
        // if one element
        else if (front == rear)
            front = rear = -1;
        // circular condition
        else if (rear == 0)
            rear = size - 1;
        else
        {
            arr[rear] = -1;
            rear--;
        }
        return true;
    }

    int getFront()
    {
        if (front == -1 and rear == -1)
            return -1;
        else
            return arr[front];
    }

    int getRear()
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
        if ((front == 0 and rear == size - 1) or (rear == front - 1))
            return true;
        else
            return false;
    }
};

int main()
{
    MyCircularDeque circularDeque(5); // Creating a circular deque of size 5

    cout << "Is empty: " << circularDeque.isEmpty() << endl; // Should print 1 (true)

    circularDeque.insertFront(1);
    circularDeque.insertFront(2);
    circularDeque.insertLast(3);

    cout << "Front: " << circularDeque.getFront() << endl; // Should print 2
    cout << "Rear: " << circularDeque.getRear() << endl;   // Should print 3

    cout << "Is empty: " << circularDeque.isEmpty() << endl; // Should print 0 (false)
    cout << "Is full: " << circularDeque.isFull() << endl;   // Should print 0 (false)

    circularDeque.deleteFront();

    cout << "Front after deleteFront: " << circularDeque.getFront() << endl; // Should print 1

    circularDeque.insertLast(4);
    circularDeque.insertLast(5);

    cout << "Is full: " << circularDeque.isFull() << endl; // Should print 0

    circularDeque.deleteLast();
    circularDeque.deleteLast();
    circularDeque.deleteLast();
    circularDeque.deleteLast();

    cout << "Is empty: " << circularDeque.isEmpty() << endl; // Should print 1 (true)

    return 0;
}