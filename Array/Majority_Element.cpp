#include<bits/stdc++.h>
using namespace std;

int MajorityElement(int a[],int n)
{
    int ans = 0;
    int count = 1;

    for(int i = 1; i < n; i++)
    {
        if(a[ans] == a[i])
        count++;
        else
        count--;

        if(count == 0)
        {
            ans = i;
            count = 1;
        }
    }

    count = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[ans] == a[i])
        count++;
    }

    if(count > int(n/2))
    return ans;

    return -1;
}

int main()
{
    int nums[] = {2,2,1,1,1,2,2};
    int n = sizeof(nums)/sizeof(int);

    int pos = MajorityElement(nums,n);

    cout << nums[pos] << endl;

    return 0;
}