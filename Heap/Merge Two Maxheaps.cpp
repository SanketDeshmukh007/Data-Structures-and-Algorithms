#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maxi = i;

    if (left < n and a[left] > a[maxi])
        maxi = left;
    if (right < n and a[right] > a[maxi])
        maxi = right;

    if (maxi == i)
        return;

    swap(a[i], a[maxi]);
    heapify(a, n, maxi);
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b)
{

    for (auto x : b)
        a.push_back(x);

    int size = a.size();
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(a, size, i);
    }
    return a;
}

int main()
{
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    vector<int> ans = mergeHeaps(a,b);
    for(auto x : ans)
    cout << x << " ";
    cout << endl;

    return 0;
}