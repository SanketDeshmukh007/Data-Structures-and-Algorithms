#include<bits/stdc++.h>
using namespace std;

class abc
{
    public:
    static int x;
    static int y;

    void print() const
    {
        cout << x << " " << y << endl;
    }

    static void display()
    {
        // We can access only static variables and not instance variables
        // No this pointer is accessible
        // cout << this->x << endl; X
        cout << x << " " << y << endl;
    }
};

int abc::x;
int abc::y;

int main()
{
    abc obj1;
    obj1.x = 1;
    obj1.y = 2;
    obj1.display();
    abc::display();
    abc obj2;
    obj2.x = 10;
    obj2.y = 20;
    obj2.display();
    abc::display();

    return 0;
}