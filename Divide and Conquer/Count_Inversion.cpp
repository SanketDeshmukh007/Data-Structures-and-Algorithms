#include <bits/stdc++.h>
using namespace std;

int Merge(int *arr, int start, int mid, int end)
{
    int inversionCount = 0;
    int m = mid - start + 1;
    int n = end - mid;
    int a[m], b[n];

    // Copy data to temporary arrays
    for (int i = 0; i < m; i++)
        a[i] = arr[start + i];
    for (int i = 0; i < n; i++)
        b[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = start;
    while (i < m and j < n)
    {
        if (a[i] <= b[j])
        { // Use <= instead of < to maintain stability
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = b[j++];
            inversionCount += m - i;
        }
    }

    while (i < m)
        arr[k++] = a[i++];

    while (j < n)
        arr[k++] = b[j++];

    return inversionCount;
}

int MergeSort(int *arr, int start, int end)
{
    int inversionCount = 0;

    if (start < end)
    {
        int mid = start + (end - start) / 2;

        inversionCount += MergeSort(arr, start, mid);
        inversionCount += MergeSort(arr, mid + 1, end);
        inversionCount += Merge(arr, start, mid, end);
    }
    return inversionCount;
}

int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    int n = 5;
    int start = 0;
    int end = n - 1;

    cout << MergeSort(arr, start, end) << endl;

    return 0;
}
