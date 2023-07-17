#include <bits/stdc++.h>
using namespace std;

int count(int n)
{
    // Base Case
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    int i = 1;
    int end = sqrt(n);
    int mini = INT_MAX;

    while (i <= end)
    {
        int perfectSquare = i * i;
        int ans = 1 + count(n - perfectSquare);
        mini = min(mini, ans);
        i++;
    }
    return mini;
}

int numSquares(int n)
{
    return count(n) - 1;
}

int main()
{
    cout << numSquares(12) << endl;

    return 0;
}