#include<bits/stdc++.h>
using namespace std;

void Transpose(int matrix[][3])
{
    int transpose[3][3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int matrix[3][3] = {{2,4,6},{1,3,5},{9,11,13}};
    Transpose(matrix);

    return 0;
}