#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int *arr,int n)
{
    for(int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        
        while(arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = current;
    }
}

int main()
{
    int arr[10] = {10, 82, 93, 46, 58, 69, 34, 27, 62, 79};
    int n = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(arr, n);
    // After applying Insertion sort on array
    cout << "After Sorting" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}