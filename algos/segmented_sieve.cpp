#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void simpleSieve(ll limit, vector<ll> &prime)
{
    bool mark[limit + 1];
    memset(mark, true, sizeof(mark));

    for (ll p = 2; p * p < limit; p++)
    {
        if (mark[p] == true)
        {
            for (ll i = p * 2; i < limit; i += p)
                mark[i] = false;
        }
    }
    for (ll p = 2; p < limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
        }
    }
}

vector<ll> segmentedSieve(ll n)
{

    ll limit = floor(sqrt(n)) + 1;
    vector<ll> prime;
    vector<ll> primes;
    simpleSieve(limit, prime);
    primes = prime;
    ll low = limit;
    ll high = 2 * limit;

    while (low < n)
    {
        if (high >= n)
            high = n;
        bool mark[limit + 1];
        memset(mark, true, sizeof(mark));
        for (ll i = 0; i < prime.size(); i++)
        {
            ll loLim = floor(low / prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];

            for (ll j = loLim; j < high; j += prime[i])
                mark[j - low] = false;
        }

        for (ll i = low; i < high; i++)
            if (mark[i - low] == true)
                primes.push_back(i);

        low = low + limit;
        high = high + limit;
    }
    return primes;
}