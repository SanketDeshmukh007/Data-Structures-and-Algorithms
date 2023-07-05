#include<bits/stdc++.h>
using namespace std;

// void solve(int*& p)
// {
//     p = p + 1;
// }

int* solve()
{
    int a = 5;
    int *p = &a;
    return p;
}

int main()
{
    // int a = 5;
    // int& b = a;

    // cout << a << endl;
    // cout << b << endl;

    // a = a + 1;

    // cout << a << endl;
    // cout << b << endl;

    // b = b + 1;

    // cout << a << endl;
    // cout << b << endl;

    // int a = 5;
    // int *p = &a;
    // cout << p << endl;

    // solve(p);

    // cout << p << endl;

    int * ans = solve();
    // cout << ans << endl;
    cout << *ans << endl;

    return 0;
}