
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
#define N 1000006
#define mod 998244353
ll n, x;
v<ll> a(N), cummin(N, INT_MAX), cummax(N, INT_MAX), cummin1(N, INT_MAX), cummax1(N, 0), cummax2(N, 0);
set<ll> nos, nos1;
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
    cin >> n >> x;
    ll m1 = -1, m2 = INT_MAX;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        auto itr = nos.upper_bound(a[i]);
        if (itr != nos.end())
            cummax[a[i]] = min(cummax[a[i]], *itr);
        nos.insert(a[i]);
    }
    for (ll i = 1; i <= x; i++)
    {
        if (cummax[i] > 0)
            cummin1[i] = min(cummax[i], cummin1[i - 1]);
        else
            cummin1[i] = cummin1[i - 1];
        // cout << cummin1[i] << " ";
    }
    // cout << "\n";
    for (ll i = n; i >= 1; i--)
    {
        if (m2 < a[i])
            cummin[a[i]] = min(cummin[a[i]], m2);
        m2 = min(m2, a[i]);
        // cout << i << " " << cummin[a[i]] << " ";
        nos1.insert(a[i]);
        auto itr = nos1.lower_bound(a[i]);
        if (itr == nos1.begin())
            continue;
        itr--;
        cummax1[a[i]] = max(cummax1[a[i]], *itr);
    }
    for (ll i = x; i >= 1; i--)
    {
        cummax2[i] = max(cummax1[i], cummax2[i + 1]);
        // cout << i << " " << cummax2[i] << " ";
    }
    // cout << "\n";
    m1 = x;
    ll ans = 0;
    for (ll r = x; r >= 1; r--)
    {
        ll l = r;
        if (r < cummax2[r + 1])
            continue;
        m1 = min(m1, cummin[r + 1]);
        l = min(m1, r);
        l = min(l, cummin1[r - 1]);
        ans += l;
    }
    cout << ans << "\n";
}