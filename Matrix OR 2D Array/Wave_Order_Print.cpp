#include<bits/stdc++.h>
using namespace std;

vector<int> WaveOrderPrint(vector<vector<int>> matrix)
{
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();
    int top = 0;
    int bottom = row - 1;

    for(int j = 0; j < col; j++)
    {
        // if col is even
        if(j % 2 == 0)
        {
            for(int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][j]);
            }
        }
        else
        {
            for(int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][j]);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{2,4,6},{1,3,5},{9,11,13}};
    vector<int> ans = WaveOrderPrint(matrix);

    for(auto x : ans)
    cout << x << " ";

    return 0;
}