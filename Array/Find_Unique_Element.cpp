#include<bits/stdc++.h>
using namespace std;

int uniqueElement(vector<int> a)
{
    int n = a.size();
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        ans = ans ^ a[i];
    }
    return ans;
}

int main()
{
    vector<int> a = {1,2,3,4,1,3,4};
    cout << uniqueElement(a) << endl;

    return 0;
}