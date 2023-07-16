#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr,int n,int m,int mid)
{
    int studentcount = 1;
    int pageSum = 0;

    for(int i = 0; i < n; i++)
    {
        if(pageSum + arr[i] <= mid)
        pageSum += arr[i];
        else
        {
            studentcount++;

            if(studentcount > m or arr[i] > mid)
            return false;

            pageSum = 0;
            pageSum += arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr,int n,int m)
{
    if(m > n) // each student must get at least one book
    return -1;

    int ans = -1;

    int start = *max_element(arr.begin(),arr.end());
    int end = accumulate(arr.begin(),arr.end(),0);

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(isPossible(arr,n,m,mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        start = mid + 1;
    }

    return ans;
}

// The task is to assign books in such a way that the maximum 
// number of pages assigned to a student is minimum

int main()
{
    vector<int> arr = {12,34,67,90};
    int n = 4; // no. of books
    int m = 2; // no. of students

    cout << findPages(arr,n,m) << endl;

    return 0;
}