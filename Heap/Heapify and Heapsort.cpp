#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int maxi = i;

    if(left < n and arr[maxi] < arr[left])
    maxi = left;
    if(right < n and arr[maxi] < arr[right])
    maxi = right;

    if(maxi == i) return;
    
    swap(arr[i],arr[maxi]);
    heapify(arr,n,maxi);
}

void buildHeap(int arr[],int n)
{
    for(int i = n/2; i > 0; i--)
    {
        heapify(arr,n,i);
    }
}

void heapSort(int arr[],int n)
{
    while(n != 1)
    {
        int first = 1;
        int last = n-1;

        swap(arr[first],arr[last]);
        n--;

        heapify(arr,n,first);
    }
}

int main()
{
    int arr[] = {-1,12,15,13,11,14};
    int n = 6;
    buildHeap(arr,n);

    for(int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr,n);
    for(int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}