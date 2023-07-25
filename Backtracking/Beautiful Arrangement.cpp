#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &index, int &ans, int currNum, int n)
{
    // Base Case
    if (currNum == n + 1)
    {
        ans++;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (index[i] == 0 and (currNum % i == 0 or i % currNum == 0))
        {
            index[i] = currNum;
            solve(index, ans, currNum + 1, n);
            index[i] = 0;
        }
    }
}

int countArrangement(int n)
{
    vector<int> index(n + 1);
    int ans = 0;
    int currNum = 1;
    solve(index, ans, currNum, n);
    return ans;
}

int main()
{
    cout << countArrangement(3) << endl;

    return 0;
}