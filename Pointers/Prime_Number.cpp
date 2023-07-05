#include<bits/stdc++.h>
using namespace std;

bool Prime(int n)
{
    for(int i = 2;i < n; i++)
    {
        if(n % i == 0)
        return false;
    }

    return true;
}

int main()
{
    int n = 11;
    if(Prime(n))
    cout << "Prime" << endl;
    else cout << "Not Prime" << endl;

    return 0;
}