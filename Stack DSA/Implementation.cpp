#include<bits/stdc++.h>
using namespace std;

class Stack
{
    int *arr;
    int size;
    int top;

    public:

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    // Functions
    void push(int data)
    {
        top++;
        if(top >= 0 and top < size)
        {
            arr[top] = data;
        }
        else
        {
            cout << "Stack Overflow" << endl;
            top--;
        }
    }

    void pop()
    {
        if(top < 0)
        cout << "Stack Underflow" << endl;
        else
        {
            cout << "Popped element is: " << arr[top] << endl;
            top--;
        }
    }

    int getTop()
    {
        if(top < 0) return -1;

        return arr[top];
    }

    int getSize()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        if(top == -1)
        return true;
        else return false;
    }
};


int main()
{
    /*
    stack<int> s;

    // Insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << s.top() << endl;

    // Removal
    s.pop();
    cout << s.top() << endl;

    cout << s.size() << endl;

    cout << s.empty() << endl;

    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    */

   Stack s(5);
   s.push(10);
   s.push(20);
   s.push(30);
   s.push(40);
   s.push(50);
   s.push(60);

   /*
   cout << s.getTop() << endl;
   s.pop();
   cout << s.getTop() << endl;
   cout << s.getSize() << endl;
   cout << s.isEmpty() << endl;
   */
   /*
   s.pop();
   cout << s.getTop() << endl;
   s.pop();
   cout << s.getTop() << endl;
   s.pop();
   cout << s.getTop() << endl;
   s.pop();
   cout << s.getTop() << endl;
   s.pop();
   
  s.push(50);
  s.push(60);
  */

  while(!s.isEmpty())
  {
    cout << s.getTop() << " ";
    s.pop();
  }

  cout << s.getSize() << endl;
  s.pop();

    return 0;
}