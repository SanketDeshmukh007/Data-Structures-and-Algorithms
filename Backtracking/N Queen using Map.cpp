#include <bits/stdc++.h>
using namespace std;

unordered_map<int,bool> leftRow;
unordered_map<int,bool> upperLeftDiagonal;
unordered_map<int,bool> bottomLeftDiagonal;

bool isSafe(int row, int col, int n)
{
    if(leftRow[row] == true)
    return false;

    if(upperLeftDiagonal[n-1+col-row] == true)
    return false;

    if(bottomLeftDiagonal[col+row] == true)
    return false;

    return true;
}

void solve(vector<vector<char>> &board, int n, int col, vector<vector<string>> &ans)
{
    // Base Case
    if (col >= n)
    {
        vector<string> temp;
        for(int i = 0; i < n; i++)
        {
            string output;
            for(int j = 0; j < n; j++)
            {
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, n))
        {
            board[row][col] = 'Q';
            leftRow[row] = true;
            upperLeftDiagonal[n-1+col-row] = true;
            bottomLeftDiagonal[row+col] = true;

            // Recursive Call
            solve(board, n, col + 1, ans);
            // Backtracking
            board[row][col] = '.';
            leftRow[row] = false;
            upperLeftDiagonal[n-1+col-row] = false;
            bottomLeftDiagonal[row+col] = false;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    int col = 0;
    solve(board, n, col, ans);
    return ans;
}

int main()
{
    vector<vector<string>> ans = solveNQueens(4);
    for(auto &x : ans)
    {
        for(auto &y : x)
        {
            cout << y << endl;
        }
        cout << endl;
    }

    return 0;
}