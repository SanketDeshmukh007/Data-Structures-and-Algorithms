#include <iostream>
using namespace std;

int MissingElement(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int index = abs(a[i]);

        if (a[index - 1] > 0)
            a[index - 1] = -a[index - 1];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            return i + 1;
    }
    return -1;
}

int main()
{
    int a[] = {1, 3, 5, 3, 4};

    cout << MissingElement(a, 5) << endl;
    return 0;
}
