#include<bits/stdc++.h>
using namespace std;

void countSetBits(int n)
{
    int count = 0;
    while(n > 0)
    {
        n = n & (n - 1);
        count++;
    }
    cout << count << endl;
}

int main()
{
    // int n = 7;
    // int count = 0;
    // while(n > 0)
    // {
    //     if(n & 1)
    //         count++;
    //     n = n >> 1;
    // }
    // cout << count << endl;
    countSetBits(7);

    return 0;
}