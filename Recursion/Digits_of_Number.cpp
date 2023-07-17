#include<bits/stdc++.h>
using namespace std;

void printDigits(int num)
{
    // 1. Base Case
    if(num == 0)
    return;

    // 2. Recursive Relation
    printDigits(num / 10);

    // 3. Processing
    cout << num % 10 << " ";

}

int main()
{
    int num = 2345;
    printDigits(num);

    return 0;
}