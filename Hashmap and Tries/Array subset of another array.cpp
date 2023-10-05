#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m1)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a1[i]]++;
    }

    string ans = "Yes";
    for (int i = 0; i < m1; i++)
    {
        if (m[a2[i]] == 0)
            ans = "No";
        else
            m[a2[i]]--;
    }
    return ans;
}

int main()
{
    //

    return 0;
}