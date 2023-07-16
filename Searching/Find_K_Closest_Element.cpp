#include <bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> ans;
    int start = 0;
    int end = arr.size()-1;

    while(end - start >= k)
    {
        // Go with smaller difference
        if(x - arr[start] > arr[end] - x)
        start++;
        else
        end--;
    }
    for(int i = start; i <= end; i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    int k = 4, x = 3;
    vector<int> ans = findClosestElements(arr,k,x);
    for(auto x : ans)
    cout << x << " ";

    return 0;
}