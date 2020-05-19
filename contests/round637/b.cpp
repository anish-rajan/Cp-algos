#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define pii pair<ll, ll>
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 200005
#define mod 998244353

ll t;

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
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        v<ll> a(n + 3), cum(n + 3), is_peak(n + 3);
        a = {0};
        cum = {0};
        is_peak = {0};
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        cum[n] = 0;
        for (ll i = n - 1; i > 1; i--)
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                cum[i] = cum[i + 1] + 1;
                is_peak[i] = 1;
            }
            else
                cum[i] = cum[i + 1];
            // cout << i << " " << cum[i] << "\n";
        }
        cum[1] = cum[2];
        ll maxans = 0, l = n;
        for (ll i = n - k + 1; i >= 1; i--)
        {
            if (cum[i] - cum[i + k] - is_peak[i + k - 1] >= maxans && cum[i] == cum[i + 1])
            {
                maxans = cum[i] - cum[i + k] - is_peak[i + k - 1];
                l = min(l, i);
            }
            // cout << i << " " << maxans << " " << l << " " << cum[i] - cum[i + k] << "\n";
        }
        cout << maxans + 1 << " " << l << "\n";
    }
}