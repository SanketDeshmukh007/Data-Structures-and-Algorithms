#include<bits/stdc++.h>
using namespace std;

bool arraySortedOrNot(int *arr,int n)
{
    // 1. Base Case
    if(n == 1)
    return true;

    // 2. Processing
    if(arr[0] > arr[1])
    return false;

    // 3. Recursive Relation
    return arraySortedOrNot(arr+1,n-1);
}

int main()
{
    int arr[] = {10,35,30,40,50};
    int n = sizeof(arr)/sizeof(int);

    if(arraySortedOrNot(arr,n))
    {
        cout << "Sorted" << endl;
    }
    else cout << "Not Sorted" << endl;

    return 0;
}