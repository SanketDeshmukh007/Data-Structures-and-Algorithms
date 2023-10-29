#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n = 10;
    int i = 1;
    int mask = ~(1 << i);
    int ans = n & mask;
    cout << ans << endl;

    return 0;
}