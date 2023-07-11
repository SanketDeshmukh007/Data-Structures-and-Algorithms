#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int num)
{
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;

    for(int i = 2; i <= num; i++)
    {
        for(int j = 0; j < int(ans.size()); j++)
        {
            int prod = ans[j] * i + carry;
            int digit = prod % 10;
            carry = prod / 10;
            ans[j] = digit;
        }

        while(carry != 0)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
        }
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    vector<int> fact = factorial(number);
    cout << "Factorial of " << number << " is: ";
    for(auto x : fact)
    cout << x;

    return 0;
}
