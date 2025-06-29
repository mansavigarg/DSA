// ! Segmented Sieve

#include <iostream>
using namespace std;

vector<bool> Sieve(int n)
{
    // create a sieve array of N size telling isPrime
    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                prime[j] = false; // making all the multiple of i as non-prime
            }
        }
    }
    return prime;
}

// code of segmented sieve

vector<bool> segSieve(int L, int R)
{
    // get me the prime array, it will be used to mark the segmented sieve
    vector<bool> sieve = Sieve(sqrt(R));
    vector<int> basePrimes;

    for (int i = 0; i < sieve.size(); i++)
    {
        if (sieve[i])
        {
            basePrimes.push_back(i);
        }
    }

    vector<bool> segSieve(R - L + 1, true);
    if (L == 1 || L == 0)
    {
        segSieve[0] = false;
    }

    for (auto prime : basePrimes)
    {
        int first_mul = (L / prime) * prime;

        if (first_mul < L)
        {
            first_mul += prime;
        }

        for (int j = max(first_mul, prime * prime); j <= R; j = j + prime)
        {
            segSieve[j - L] = 0;
        }
    }
    return segSieve;
}

int main()
{
    int L = 110;
    int R = 130;
    vector<bool> ansSegSieve = segSieve(L, R);

    for (int i = 0; i < ansSegSieve.size(); i++)
    {
        if (ansSegSieve[i])
        {
            cout << i + L << " ";
        }
    }

    cout << endl;
    return 0;
}