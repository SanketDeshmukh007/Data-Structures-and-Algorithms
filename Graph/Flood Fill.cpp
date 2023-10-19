#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int m, int n, int currColor, vector<vector<int>> &image)
{
    if ((i >= 0 and i < m) and (j >= 0 and j < n) and image[i][j] == currColor)
        return true;

    return false;
}

void dfs(int i, int j, int m, int n, int color, int currColor, vector<vector<int>> &image)
{
    if (color == currColor)
        return;

    image[i][j] = color;

    if (isValid(i + 1, j, m, n, currColor, image))
        dfs(i + 1, j, m, n, color, currColor, image);
    if (isValid(i - 1, j, m, n, currColor, image))
        dfs(i - 1, j, m, n, color, currColor, image);
    if (isValid(i, j + 1, m, n, currColor, image))
        dfs(i, j + 1, m, n, color, currColor, image);
    if (isValid(i, j - 1, m, n, currColor, image))
        dfs(i, j - 1, m, n, color, currColor, image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int m = image.size();
    int n = image[0].size();

    int currColor = image[sr][sc];
    dfs(sr, sc, m, n, color, currColor, image);
    return image;
}

int main()
{
    // Define your input image as a 2D vector of integers.
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    int sr = 1;       // Starting row
    int sc = 1;       // Starting column
    int newColor = 2; // New color

    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    // Print the result
    for (const auto &row : result)
    {
        for (int pixel : row)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}