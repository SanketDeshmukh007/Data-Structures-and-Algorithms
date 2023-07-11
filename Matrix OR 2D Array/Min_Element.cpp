#include<bits/stdc++.h>
using namespace std;

int MinElement(int a[3][3])
{
    int mini = INT_MAX;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            mini = min(mini,a[i][j]);
        }
    }
    return mini;
}

int main()
{
    int a[3][3] = {{5,7,9},{12,4,2},{1,6,7}};
    int mini = MinElement(a);
    cout << mini << endl;

    return 0;
}