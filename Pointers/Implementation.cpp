#include <bits/stdc++.h>
using namespace std;

// void solve(int arr[])
// {
//     // cout << "Size of arr in solve function : " << sizeof(arr) << endl;
//     cout << arr << endl;
//     cout << &arr << endl;

//     arr[0] = 50;
// }

void util(int *p)
{
    // p = p + 1;
    *p = *p + 1;
}

int main()
{
    // int a = 5;
    // // int b = 5;

    // // cout << a << endl;
    // // cout << &a << endl;
    // // cout << &b << endl;

    // int *p = &a;
    // cout << "Value stored at a : " << a << endl;
    // cout << "Value stored at p : " << p << endl;
    // cout << "Value at address : " << *p << endl;
    // cout << "Address of a : " << &a << endl;
    // cout << "Address of p : " << &p << endl;

    // cout << sizeof(p) << endl;

    // BAD PRACTICE
    // int *p;
    // cout << *p << endl;

    // NULL POINTER
    // int *p = 0;
    // int *p = NULL;
    // int *p = nullptr;
    // cout << *p << endl;

    // POINTER ARITHMETIC
    // int a = 5;
    // int *p = &a;
    // cout << p << endl;
    // cout << p + 1 << endl;

    // COPY POINTER
    // int a = 5;
    // int *p = &a;
    // int *q = p;
    // cout << *p << " " << *q << endl;

    // int a[4] = {20,30,40,50};
    // cout << a << endl;
    // cout << a[0] << endl;
    // cout << &a << endl;
    // cout << &a[0] << endl;

    // int *p = a;
    // cout << p << endl;
    // cout << &p << endl;
    // cout << *p << endl;
    // cout << *a << endl;
    // cout << *a + 1 << endl;
    // cout << *(a) + 1 << endl;
    // cout << *(a + 1) << endl;
    // cout << *(a + 2) << endl;

    // int i = 0;
    // cout << a[i] << endl;
    // cout << i[a] << endl;
    // cout << *(a + i) << " " << *(i + a) << endl;

    // int arr[10];
    // int *p = arr;
    // cout << sizeof(arr) << endl;
    // cout << sizeof(p) << endl;
    // cout << sizeof(*p) << endl;

    // char ch[10] = "Babbar";
    // char *c = ch;
    // cout << ch << endl;
    // cout << ch[0] << endl;
    // cout << &ch << endl;

    // cout << c << endl;
    // cout << &c << endl;
    // cout << *c << endl;

    // char name[10] = "SherBano";
    // char *c = &name[0];

    // cout << name << endl;
    // cout << &name << endl;
    // cout << *(name + 3) << endl;
    // cout << c << endl;
    // cout << &c << endl;
    // cout << *(c + 3) << endl;
    // cout << c + 2 << endl;
    // cout << *c << endl;
    // cout << c + 8 << endl;

    // char ch = 'k';
    // char *c = &ch;
    // cout << c << endl;

    // char name[10] = "babbar";
    // cout << name << endl;

    // // BAD PRACTICE
    // char *c = "babbar";
    // cout << c << endl;

    // int arr[10] = {1,2,3,4};
    // // cout << "Size of arr in main function : " << sizeof(arr) << endl;
    // cout << "Before Function Call" << endl;
    // cout << arr << endl;
    // cout << &arr << endl;
    // for(auto x : arr)
    // cout << x << " ";

    // cout << endl;

    // cout << "After Function Call" << endl;
    // solve(arr);
    // for(auto x : arr)
    // cout << x << " ";

    int a = 5;

    int *p = &a;

    cout << "before" << endl;
    cout << a << endl;
    cout << p << endl;
    cout << *p << endl;

    util(p);

    cout << "after" << endl;
    cout << a << endl;
    cout << p << endl;
    cout << *p << endl;

    return 0;
}