#include<bits/stdc++.h>
using namespace std;

int MaxElement(int a[3][3])
{
    int maxi = INT_MIN;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            maxi = max(maxi,a[i][j]);
        }
    }
    return maxi;
}

int main()
{
    int a[3][3] = {{5,7,9},{12,4,2},{1,6,7}};
    int maxi = MaxElement(a);
    cout << maxi << endl;

    return 0;
}