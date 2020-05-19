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
#define N 200005
#define mod 998244353
ll n;
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
    cin >> n;
    ll prod = 1;
    ll sum = 1;
    ll p1 = powmod(100, mod - 2, mod);
    for (ll i = 1; i <= n; i++)
    {
        ll val;
        cin >> val;
        val = (val * p1) % mod;
        prod = (prod * val) % mod;
        if (i <= n - 1)
            sum = (sum + prod) % mod;
        // cout << val << " " << prod << " " << sum << " ";
    }
    sum = (sum * powmod(prod, mod - 2, mod)) % mod;
    cout << sum << "\n";
}