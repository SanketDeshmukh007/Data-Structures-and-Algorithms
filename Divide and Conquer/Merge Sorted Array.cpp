#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    for (int j = 0, i = m; j < n; j++)
    {
        nums1[i] = nums2[j];
        i++;
    }

    sort(nums1.begin(), nums1.end());
}

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0},nums2 = {2,5,6};
    int m = 3, n = 3;
    merge(nums1,m,nums2,n);

    for(auto x : nums1)
    cout << x << " ";

    return 0;
}