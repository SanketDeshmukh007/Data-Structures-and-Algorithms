#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 3;

    priority_queue<int> p;
    // Insert first k elements into queue
    for (int i = 0; i < k; i++)
    {
        p.push(arr[i]);
    }

    // for remaining element insert only elements less than top
    for (int i = k; i < n; i++)
    {
        if (arr[i] < p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }

    cout << p.top() << endl;

    return 0;
}