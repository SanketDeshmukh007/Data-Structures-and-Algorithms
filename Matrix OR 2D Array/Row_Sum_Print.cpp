#include<bits/stdc++.h>
using namespace std;

void RowSumPrint(int a[][3])
{
    for(int i = 0; i < 3; i++)
    {
        int sum = 0;
        for(int j = 0; j < 3; j++)
        {
            sum = sum + a[i][j];
        }
        cout << "Row " << i+1 << ": " << sum << endl;
    }
}

int main()
{
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    RowSumPrint(a);

    return 0;
}