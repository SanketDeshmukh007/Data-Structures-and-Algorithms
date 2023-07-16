#include<bits/stdc++.h>
using namespace std;

int MissingElement(vector<int>& a)
{
    int start = 0;
    int end = a.size() - 1;

    while(end - start > 1)
    {
        int mid = start + (end - start)/2;

        if(a[start]-start != a[mid] - mid)
        end = mid;
        else if(a[end]-end != a[mid]-mid)
        start = mid;
    }
    return a[start] + 1;
}

int main()
{
    vector<int> a = {1,2,3,4,6,7,8};

    cout << "Missing Element is: " << MissingElement(a) << endl;

    return 0;
}