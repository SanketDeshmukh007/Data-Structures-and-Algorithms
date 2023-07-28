// >> --> Insertion Operator
// << --> Extraction Operator

/*
Points:
1. Why we need to overload?
--> cout << (user defined type) or cin >> (user defined type) e.g class object
2. It cannot be class member function , we have to declare them as friend function

cout is a object of ostream class
cin is a object of istream class
*/

#include<iostream>
using namespace std;

class test
{
    int x;
    public:
    test(int val = 0)
    {
        x = val;
    }

    friend istream& operator >> (istream& input,test& obj);
    friend ostream& operator << (ostream& output,test& obj);
};

istream& operator >> (istream& input,test& obj)
{
    input >> obj.x;
    return input;
}

ostream& operator << (ostream& output,test& obj)
{
    output << obj.x << endl;
    return output;
}

int main()
{
    test t;
    cin >> t;
    cout << t;
}
