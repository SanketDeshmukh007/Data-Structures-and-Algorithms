#include<bits/stdc++.h>
using namespace std;

class test
{
    public:
    int val;

    void operator+(test& obj2)
    {
        int val1 = this->val;
        int val2 = obj2.val;
        cout << val1 - val2 << endl;
    }
};

int main()
{
    test t1 , t2;
    t1.val = 7;
    t2.val = 2;
    t1.operator+(t2);

    return 0;
}