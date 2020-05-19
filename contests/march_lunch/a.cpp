#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 10004
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll t;
ll lcm(ll val1, ll val2)
{
    return (val1 * val2) / __gcd(val1, val2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> primes;
    vector<ll> prime_check(N);
    for (ll i = 2; i <= 10001; i++)
    {
        if (!prime_check[i])
            for (ll j = 2 * i; j <= 10001; j += i)
            {
                prime_check[j] = 1;
            }
    }
    for (ll i = 2; i <= 10001; i++)
    {
        if (!prime_check[i])
            primes.push_back(i);
    }
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> arr(n);
        ll l = 1;
        vector<ll> max_pows(m + 1);
        max_pows = {0};
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (ll i = 0; i < n; i++)
        {
            ll temp = arr[i];
            for (ll j = 0; primes[j] <= (ll)sqrt(arr[i]); j++)
            {
                ll temp1 = 0;
                while (temp % primes[j] == 0)
                {
                    temp1++;
                    temp /= primes[j];
                }
                max_pows[primes[j]] = max(max_pows[primes[j]], temp1);
            }
            if (temp != 1)
                max_pows[temp] = max(max_pows[temp], (ll)1);
        }
        ll max_mult = 1, val = 1;
        for (ll i = 1; i <= m; i++)
        {
            ll temp = i, prod = 1;
            for (ll j = 0; primes[j] <= (ll)sqrt(i); j++)
            {
                ll temp1 = 0, power = 0;
                while (temp % primes[j] == 0)
                {
                    temp1++;
                    temp /= primes[j];
                }
                power = max((ll)0, temp1 - max_pows[primes[j]]);
                prod *= (ll)pow(primes[j], power);
            }
            if (temp != 1 && max_pows[temp] == 0)
            {
                prod *= temp;
            }
            if (prod > max_mult)
            {
                max_mult = prod;
                val = i;
            }
            // cout << prod << " " << val << "\n";
        }
        cout << val << "\n";
    }
}