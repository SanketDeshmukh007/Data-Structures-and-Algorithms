#include<bits/stdc++.h>
using namespace std;

class heap
{
    public:
    int *arr;
    int size;

    heap()
    {
        arr = new int[100];
        size = 0;
    }

    void insert(int val)
    {
        // 1. Insert at last pos in array
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index != 1) // index / 2 -- 0
        {
            if(arr[index] > arr[index/2])
            {
                swap(arr[index],arr[index/2]);
                index = index / 2;
            }
            else break;            
        }
    }

    void Delete()
    {
        int ans = arr[1];
        cout << ans << endl;
        arr[1] = arr[size];
        size--;
        int index = 1;

        while(index < size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;
            int maxi = index;

            if(left < size and arr[maxi] < arr[left])
            maxi = left;
            if(right < size and arr[maxi] < arr[right])
            maxi = right;

            if(maxi == index)
            break;
            else
            {
                swap(arr[index],arr[maxi]);
                index = maxi;
            }
        }
    }
};

int main()
{
    heap h;
    h.arr[0] = -1;
    // h.arr[1] = 100;
    // h.arr[2] = 50;
    // h.arr[3] = 60;
    // h.arr[4] = 40;
    // h.arr[5] = 45;
    // h.size = 5;
    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);

    for(int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    h.Delete();
    for(int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    // h.insert(110);
    // for(int i = 0; i <= h.size; i++)
    // {
    //     cout << h.arr[i] << " ";
    // }
    // cout << endl;

    return 0;
}