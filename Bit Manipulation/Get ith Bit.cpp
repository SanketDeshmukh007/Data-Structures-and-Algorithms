#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    int i = 1; // Bit Position
    int mask = 1 << i;

    if(n & mask) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}