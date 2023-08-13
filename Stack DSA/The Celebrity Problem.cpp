#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (M[a][b])
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    int celeb = s.top();
    s.pop();

    for (int i = 0; i < n; i++)
    {
        if (M[celeb][i] != 0)
            return -1;
        if (M[i][celeb] != 1 and i != celeb)
            return -1;
    }

    return celeb;
}

int main()
{
    int n = 4; // Number of people

    // Define the relationship matrix
    vector<vector<int>> M = {
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0}};

    int result = celebrity(M, n);
    if (result != -1)
    {
        cout << "The celebrity is person " << result << endl;
    }
    else
    {
        cout << "No celebrity found." << endl;
    }

    return 0;
}