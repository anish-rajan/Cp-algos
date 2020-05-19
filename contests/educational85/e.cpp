#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 31622779
#define mod 998244353
ll d, q;
ll powmod(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> d;
    v<ll> fact(105);
    fact[0] = 1;
    for (ll i = 1; i <= 102; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    v<ll> primes;
    ll temp = d;
    for (ll i = 2; i <= (ll)sqrt(d); i++)
    {
        if (temp % i == 0)
        {
            primes.pb(i);
            while (temp % i == 0)
                temp /= i;
        }
    }
    if (temp != 1)
        primes.pb(temp);
    // for (ll j = 0; j < primes.size(); j++)
    //     cout << primes[j] << " ";
    // cout << endl;
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        ll maxi = max(x, y);
        y = min(x, y);
        x = maxi;
        ll sum = 0;
        ll ans = 1;
        ll ans1 = 1;
        ll sum1 = 0;
        if (primes.size())
            for (ll j = 0; j < primes.size(); j++)
            {
                ll temp1 = 0, temp2 = 0;
                while (x % primes[j] == 0)
                {
                    temp1++;
                    x /= primes[j];
                }
                while (y % primes[j] == 0)
                {
                    temp2++;
                    y /= primes[j];
                }
                if (temp2 <= temp1)
                {
                    ans = (ans * powmod(fact[temp1 - temp2], mod - 2, mod)) % mod;
                    sum += temp1 - temp2;
                }
                else
                {
                    ans1 = (ans1 * powmod(fact[temp2 - temp1], mod - 2, mod)) % mod;
                    sum1 += temp2 - temp1;
                }
            }
        // cout << x << "\n";
        // cout << sum << "\n";
        ans1 = (ans1 * fact[sum1]) % mod;
        ans = (ans * fact[sum]) % mod;
        // cout << ans << " " << ans1 << "\n";
        ans = (ans * ans1) % mod;
        cout << ans << "\n";
    }
}