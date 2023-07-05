#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    if(a == 0)
    return b;
    if(b == 0)
    return a;

    while(a > 0 and b > 0)
    {
        if(a > b)
        a -= b;
        else
        b -= a;
    }

    return (a == 0)? b : a;
}

int LCM(int a, int b)
{
    int gcd = GCD(a,b);

    int lcm = (a * b)/gcd;

    return lcm;
}

int main()
{
    cout << LCM(50,15) << endl;
    cout << lcm(50,15) << endl;

    return 0;
}