#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 998244353
ll power(ll x, ll y)
{
    ll res = 1; // Initialize result

    x = x % mod; // Update x if it is more than or
                 // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % mod;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % mod;
    }
    return res;
}
int main()
{
    vector<ll> factmod(1000006);
    factmod[0] = 1;
    for (ll i = 1; i < 1000002; i++)
    {
        factmod[i] = (factmod[i - 1] * i) % mod;
    }
    ll n;
    cin >> n;
    ll ans = 0;
    ans += n * (factmod[n]) % mod;
    for (ll i = 1; i < n; i++)
    {
        ll temp = (factmod[n] * power(factmod[i], mod - 2)) % mod;
        ans = (ans - temp) % mod;
        if (ans < 0)
            ans += mod;
    }
    cout << ans << "\n";
}