#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a = 10;
    void *ptr = &a;
    // cout << *ptr << endl;
    cout << *(int*)ptr << endl;

    return 0;
}