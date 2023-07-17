#include<bits/stdc++.h>
using namespace std;

void printArray(int *arr,int n)
{
    // 1. Base Case
    if(n == 0)
    return;

    // 2. Processing
    cout << *arr << " ";

    // 3. Recursive Relation
    printArray(arr+1,n-1);
}

int main()
{
    int arr[] = {10,20,30,40,50};
    int n = 5;
    printArray(arr,n);

    return 0;
}