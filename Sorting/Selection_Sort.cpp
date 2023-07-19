#include <bits/stdc++.h>
using namespace std;

void selectionSort(int *arr,int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }
}

int main()
{
    int arr[10] = {10, 82, 93, 46, 58, 69, 34, 27, 62, 79};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    // After applying selection sort on array
    cout << "After Sorting" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}