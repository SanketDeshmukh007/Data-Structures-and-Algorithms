#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n = 10;
    int i = 0;
    int target = 1;
    int mask = ~(1 << i);
    // step 1 : Clear ith Bit
    n = n & mask;
    // step 2 : set ith bit with target val
    target = target << i;
    int ans = n | target;
    cout << ans << endl;

    return 0;
}