#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;

    int ans = 0;
    int i = 0;
    while(n > 0)
    {
        int digit = n % 10;
        if(digit)
        {
            ans += pow(2,i);
        }
        i++;
        n /= 10;
    }
    cout << ans << endl;

    return 0;
}