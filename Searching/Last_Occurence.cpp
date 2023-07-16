#include<bits/stdc++.h>
using namespace std;

int LastOcc(vector<int>& a,int n,int target)
{
    int ans = 0;
    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(a[mid] == target)
        {
            ans = mid;
            start = mid + 1;
        }
        else if(target > a[mid])
        start = mid + 1;
        else
        end = mid - 1;
    }
    return ans;
}

int main()
{
    vector<int> a = {1,3,4,4,4,4,4,6,7,9};
    int n = a.size();

    int ans = LastOcc(a,n,4);
    cout << "Last occurence is at: " << ans << endl;

    return 0;
}