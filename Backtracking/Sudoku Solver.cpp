#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char val)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        // Row Check
        if (board[i][col] == val)
            return false;

        // Col Check
        if (board[row][i] == val)
            return false;

        // 3X3 Box Check
        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == val)
            return false;
    }
    return true;
}

bool solve(vector<vector<char>> &board)
{
    int n = board.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
            {
                for (char ch = '1'; ch <= '9'; ch++)
                {
                    if (isSafe(board, i, j, ch))
                    {
                        board[i][j] = ch;

                        bool nextSoln = solve(board);
                        if (nextSoln == true)
                            return true;

                        board[i][j] = '.';
                    }
                }
                // 1 - 9 mdhla kontch soln nhi bhetla
                // mhnje mage kuthe tri gandly so go back
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

int main()
{
   vector<vector<char>> board =  {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
    
    solveSudoku(board);

    for(auto &x : board)
    {
        for(auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}