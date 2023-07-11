#include<bits/stdc++.h>
using namespace std;

void RowWisePrint(int a[][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    RowWisePrint(a);

    return 0;
}