#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int start, int end)
{
    int current = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= current)
            count++;
    }

    int correctIndex = start + count;
    swap(arr[start], arr[correctIndex]);

    int i = start, j = end;
    while (i < correctIndex and j > correctIndex)
    {
        while (arr[i] <= arr[correctIndex])
            i++;
        while (arr[j] > arr[correctIndex])
            j--;

        if (i < correctIndex and j > correctIndex)
        {
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }

    return correctIndex;
}

void QuickSort(int *arr, int start, int end)
{
    // Base Case
    if (start >= end)
        return;

    // Partition Logic
    int p = partition(arr, start, end);

    // Recursive Calls
    // Left
    QuickSort(arr, start, p - 1);
    // Right
    QuickSort(arr, p + 1, end);
}

int main()
{
    // int arr[] = {8,1,3,4,20,50,30};
    int arr[] = {80, 70, 60, 50, 40, 30, 20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int start = 0;
    int end = n - 1;
    QuickSort(arr, start, end);

    for (auto x : arr)
        cout << x << " ";

    return 0;
}