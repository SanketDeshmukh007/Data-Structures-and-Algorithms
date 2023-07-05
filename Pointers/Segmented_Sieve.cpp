#include <bits/stdc++.h>
using namespace std;

void sieve(int limit,vector<int> &prime)
{
    if(limit <= 1)
    return;

    vector<bool> prime1(limit+1,true);
    prime1[0] = prime1[1] = false;

    for(int i = 2; i <= limit; i++)
    {
        if(prime1[i] == true)
        {
            prime.push_back(i);
            int j = i * i;
            while(j <= limit)
            {
                prime1[j] = false;
                j += i;
            }
        }
    }
}

vector<int> segmentedSieve(int l, int h)
{
    if(l <= 1)
    l = 2;
    
    vector<int> ans;
    vector<bool> isPrime(h-l+1,true);
    int limit = sqrt(h);
    vector<int> prime;
    sieve(limit,prime);

    for(auto x : prime)
    {
        int sm = (l/x) * x; // Small Multiple
        if(sm < l)
        sm += x;

        for(int i = sm; i <= h; i += x)
        {
            if(i != x)
            isPrime[i - l] = false;
        }
    }

    for(int i = l; i <= h; i++)
    {
        if(isPrime[i - l] == true)
        ans.push_back(i);
    }

    return ans;
}

int main()
{
    int l, h;
    cout << "Enter the lower and upper bounds: ";
    cin >> l >> h;

    vector<int> primes = segmentedSieve(l, h);

    cout << "Prime numbers between " << l << " and " << h << " are: ";
    for (int prime : primes)
    {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
