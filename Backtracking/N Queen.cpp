#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, int n)
{
    // Left Row
    int i = row;
    int j = col;
    while (j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;

        j--;
    }

    // Upper Diagonal
    i = row;
    j = col;
    while (i >= 0 and j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;
        i--, j--;
    }

    // Bottom Diagonal
    i = row;
    j = col;
    while (i < n and j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;

        i++, j--;
    }

    return true;
}

void solve(vector<vector<char>> &board, int n, int col, vector<vector<string>> &ans)
{
    // Base Case
    if (col >= n)
    {
        vector<string> v;
        for (int r = n - 1; r >= 0; r--)
        {
            v.push_back(string(board[r].begin(), board[r].end()));
        }
        ans.push_back(v);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';
            // Recursive Call
            solve(board, n, col + 1, ans);
            // Backtracking
            board[row][col] = '.';
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