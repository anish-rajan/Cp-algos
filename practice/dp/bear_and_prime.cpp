#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1000006
vector<ll> arr(N), count1(10000007);
vector<pair<ll, ll>> arr1, primes;
vector<ll> cumsum;
vector<ll> prime_check(10000007);

void SieveOfEratosthenes(ll n)
{
    vector<bool> prime(n + 1);
    fill(prime.begin(), prime.end(), true);

    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (ll p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(make_pair(p, 0));
}

int main()
{
    SieveOfEratosthenes(10000002);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n;
    ll big = -1;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        count1[arr[i]]++;
        big = max(big, arr[i]);
    }
    cin >> m;
    ll sum = 0;
    for (ll i = 0; i < primes.size(); i++)
    {
        for (ll j = primes[i].first; j <= big; j += primes[i].first)
        {
            primes[i].second += count1[j];
            sum += count1[j];
        }
        cumsum.push_back(sum);
    }
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        pair<ll, ll> temp(l, 0), temp1(r, 0);
        ll ind = lower_bound(primes.begin(), primes.end(), temp) - primes.begin();
        ll ind1 = lower_bound(primes.begin(), primes.end(), temp1) - primes.begin();
        if (ind1 >= primes.size() || primes[ind1].first > r)
            ind1--;
        if (ind > 0)
            cout << cumsum[ind1] - cumsum[ind - 1] << "\n";
        else
            cout << cumsum[ind1] << "\n";
    }
}