#include <bits/stdc++.h>
using namespace std;

// Approach 1 O(N^2)
// int countPrimes(int n)
// {
//     int ans = 0;
//     for (int i = 1; i < n; i++)
//     {
//         int count = 0;
//         for (int j = 1; j <= i; j++)
//         {
//             if (i % j == 0)
//                 count++;
//         }

//         if (count == 2)
//             ans++;
//     }
//     return ans;
// }

// bool Prime(int n)
// {
//     for(int i = 2;i < n; i++)
//     {
//         if(n % i == 0)
//         return false;
//     }

//     return true;
// }
// // Approach 2 O(N^2)
// int countPrimes(int n)
// {
//     int count = 0;
//     for (int i = 2; i < n; i++)
//     {
//         if(Prime(i))
//         count++;
//     }
//     return count;
// }

// Approach 3 : Sieve of Eratosthenes
// int countPrimes(int n)
// {
//     if (n <= 1)
//         return 0;

//     int ans = 0;
//     vector<bool> prime(n, true); // All are marked prime
//     prime[0] = prime[1] == false;

//     for (int i = 2; i < n; i++)
//     {
//         if (prime[i])
//         {
//             ans++;

//             int j = 2 * i;
//             while (j < n)
//             {
//                 prime[j] = false;

//                 j += i;
//             }
//         }
//     }
//     return ans;
// }

// Approach 4 : Optimized Sieve of Eratosthenes
int countPrimes(int n)
{
    if (n <= 1)
        return 0;

    int ans = 0;
    vector<bool> prime(n, true); // All are marked prime
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            long long int j = i * i;
            while (j < n)
            {
                prime[j] = false;

                j += i;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (prime[i] == true)
            ans++;

    return ans;
}

int main()
{
    int n = 21;
    cout << countPrimes(n) << endl;

    return 0;
}