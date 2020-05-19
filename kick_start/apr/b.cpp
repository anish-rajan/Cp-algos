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
#define N 3003
ll t;
#define mod 998244353
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
    for (ll i = 1; i <= t; i++)
    {
        ll n, d;
        cin >> n >> d;
        v<ll> a(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        ll l = 1, r;
        if (d % a[1] == 0)
            r = d / a[1];
        else
            r = (d / a[1] + 1);
        ll ans = 1;
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;
            ll currday = mid * a[1];
            for (ll i = 1; i <= n; i++)
            {
                ll temp = currday / a[i];
                temp += (currday % a[i] == 0) ? 0 : 1;
                currday = temp * a[i];
            }
            if (currday <= d)
            {
                ans = max(ans, mid);
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        cout << "Case #" << i << ": " << ans * a[1] << "\n";
    }
}