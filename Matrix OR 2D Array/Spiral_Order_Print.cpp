#include<bits/stdc++.h>
using namespace std;

vector<int> SpiralPrint(vector<vector<int>> matrix)
{
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();
    int left = 0;
    int right = col - 1;
    int top = 0;
    int bottom = row - 1;
    int direction = 0;

    while(top <= bottom and left <= right)
    {
        direction = direction % 4;

        if(direction == 0)
        {
            for(int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
        }
        else if(direction == 1)
        {
            for(int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
        }
        else if(direction == 2)
        {
            for(int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        else if(direction == 3)
        {
            for(int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }

        direction++;
    }
    return ans;
}


int main()
{
    vector<vector<int>> matrix = {{2,4,6},{1,3,5},{9,11,13}};
    vector<int> ans = SpiralPrint(matrix);

    for(auto x : ans)
    cout << x << " ";
    
    return 0;
}