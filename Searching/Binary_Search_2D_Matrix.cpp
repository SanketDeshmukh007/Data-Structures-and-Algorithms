#include<bits/stdc++.h>
using namespace std;

bool search(int arr[][3],int row,int col,int target)
{
    int start = 0;
    int end = row * col - 1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int rowIndex = mid / col;
        int colIndex = mid % col;

        if(arr[rowIndex][colIndex] == target)
        return true;
        else if(target > arr[rowIndex][colIndex])
        start = mid + 1;
        else end = mid - 1;
    }
    return false;
}

int main()
{
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int target = 11;

    if(search(arr,3,3,target))
    cout << "Present" << endl;
    else cout << "Not Present" << endl;

    return 0;
}