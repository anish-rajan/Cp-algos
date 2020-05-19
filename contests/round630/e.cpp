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
ll n, m, l, r;
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
    ll ans = 0;
    cin >> n >> m >> l >> r;
    ll o, e;
    if (r % 2 == 0)
    {
        if (l % 2 == 0)
        {
            e = (r - l + 1) / 2 + 1;
            o = (r - l + 1) / 2;
        }
        else
        {
            e = (r - l + 1) / 2;
            o = (r - l + 1) / 2;
        }
    }
    else
    {
        if (l % 2 == 1)
        {
            e = (r - l + 1) / 2 + 1;
            o = (r - l + 1) / 2;
        }
        else
        {
            e = (r - l + 1) / 2;
            o = (r - l + 1) / 2;
        }
    }
    // cout << o << " " << e << "\n";
    if ((n * m) % 2 == 1)
    {
        ans = (ans + powmod(r - l + 1, n * m, mod));
    }
    else
    {
        ans = (((powmod(e + o, n * m, mod) + powmod(e - o, n * m, mod)) % mod) * powmod(2, mod - 2, mod)) % mod;
    }
    cout << ans << "\n";
}