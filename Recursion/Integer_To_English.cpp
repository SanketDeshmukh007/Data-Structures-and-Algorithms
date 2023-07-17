#include <bits/stdc++.h>
using namespace std;

vector<pair<int, string>> m = {

    {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, 
    {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, 
    {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, 
    {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, 
    {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, 
    {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, 
    {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}

};

string numberToWords(int num)
{

    if (num == 0)
        return "Zero";

    for (auto x : m)
    {
        if (num >= x.first)
        {
            string a = "";
            if (num >= 100)
            {
                a = numberToWords(num / x.first) + " ";
            }
            string b = x.second;

            string c = "";
            if (num % x.first != 0)
            {
                c = " " + numberToWords(num % x.first);
            }
            return a + b + c;
        }
    }
    return "";
}

int main()
{
    int num = 123456;

    cout << numberToWords(num) << endl;

    return 0;
}