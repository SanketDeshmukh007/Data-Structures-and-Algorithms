/*
Given an array of N integers, and an integer K, 
find the number of pairs of elements in the array 
whose sum is equal to K.
Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.
*/

#include<bits/stdc++.h>
using namespace std;

int countPairs(int arr[],int n,int k)
{
    int ans = 0;
    unordered_map<int,int> m;

    for(int i = 0; i < n; i++)
    {
        int a = arr[i];
        int b = k - a;

        if(m[b])
        ans += m[b];

        m[a]++;
    }

    return ans;
}

int main()
{
    int N = 4, K = 6;
    int arr[] = {1, 5, 7, 1};

    cout << countPairs(arr,N,K) << endl;

    return 0;
}