#include<bits/stdc++.h>
using namespace std;

int clearBitsInRange(int n,int i,int j)
{
    int a = (-1) << (i + 1);
    int b = (1 << j) - 1;
    int mask = a | b;

    return (n & mask);
}

int main()
{
    cout << clearBitsInRange(15,2,1) << endl;

    return 0;
}