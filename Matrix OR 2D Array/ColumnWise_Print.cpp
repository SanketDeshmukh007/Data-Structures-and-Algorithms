#include<bits/stdc++.h>
using namespace std;

void ColumnWisePrint(int a[][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << a[j][i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    ColumnWisePrint(a);

    return 0;
}