#include<bits/stdc++.h>
using namespace std;

void solve(int **ptr)
{
    // ptr = ptr + 1;
    // *ptr = *ptr + 1;
    **ptr = **ptr + 1;
}

int main()
{
    int a = 5;
    int *p = &a;
    int **q = &p;

    // cout << a << endl;
    // cout << &a << endl;
    // cout << p << endl;
    // cout << &p << endl;
    // cout << *p << endl;
    // cout << q << endl;
    // cout << &q << endl;
    // cout << *q << endl;
    // cout << **q << endl;

    solve(q);
    cout << a << endl;

    return 0;
}