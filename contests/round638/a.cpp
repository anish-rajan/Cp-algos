#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
ll t;
v<ll> pow2(32);
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
    cin >> t;
    pow2[0] = 1;
    for (ll i = 1; i <= 31; i++)
        pow2[i] = pow2[i - 1] * 2;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = 0, ans1 = 0;
        for (ll i = 1; i <= n / 2 - 1; i++)
        {
            ans += pow2[i];
        }
        for (ll i = n / 2; i < n; i++)
        {
            ans1 += pow2[i];
        }
        ans += pow2[n];
        cout << abs(ans - ans1) << "\n";
    }
}