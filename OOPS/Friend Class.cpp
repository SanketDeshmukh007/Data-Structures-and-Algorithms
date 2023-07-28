#include<iostream>
using namespace std;

class my
{
    private:int a = 10;
    protected: int b = 20;
    public:int c =30;
    friend class your;
};

class your
{
    public:
    my m;
    void fun()
    {
        cout<<m.a << " " << m.b << " " << m.c << endl;
    }
};

int main()
{
    your y;
    y.fun();
}