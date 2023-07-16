#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr,int start,int end,int target)
{
    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(target == arr[mid])
        return mid;
        else if(target > arr[mid])
        start = mid + 1;
        else
        end = mid - 1;
    }
    return -1;
}

int unboundedSearch(vector<int>& arr,int target)
{
    int i = 0;
    int j = 1;

    while(arr[j] <= target)
    {
        i = j;
        j = j * 2;
    }

    return search(arr,i,j,target);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
                    11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
                    21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 
                    31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 
                    41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
    
    int target = 16;

    cout << unboundedSearch(arr,target) << endl;

    return 0;
}