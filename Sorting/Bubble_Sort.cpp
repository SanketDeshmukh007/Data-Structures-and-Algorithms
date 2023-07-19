#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr,int n)
{
    // BEST CASE TIME COMPLEXITY = O(N)
    for(int i = 1; i < n; i++)
    {
        bool swapped = false;
        for(int j = 0; j < n - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j],arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false)
        return;
    }
}

int main()
{
    int arr[10] = {10, 82, 93, 46, 58, 69, 34, 27, 62, 79};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);
    // After applying Bubble sort on array
    cout << "After Sorting" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}