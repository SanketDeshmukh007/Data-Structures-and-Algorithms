#include<bits/stdc++.h>
using namespace std;

class A
{
    static int a;
    int b;
    char c;
};

class B
{
    int b;
    char c;
};

class C
{
    char b;
    int c;
};

class D
{
    char b;
    char c;
    int d;
};

class E
{
    char b;
    char c;
    char d;
    char e;
    int f;
};

class F
{
    char a;
    int b;
    char c;
    int d;
};

int main()
{
    cout << "size of A : " << sizeof(A) << endl;
    cout << "size of B : " << sizeof(B) << endl;
    cout << "size of C : " << sizeof(C) << endl;
    cout << "size of D : " << sizeof(D) << endl;
    cout << "size of E : " << sizeof(E) << endl;
    cout << "size of F : " << sizeof(F) << endl;

    return 0;
}