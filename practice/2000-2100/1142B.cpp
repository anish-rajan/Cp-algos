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
ll n, m, q;
v<ll> a(N), b(N), inv(N), par(N), last(N), rt(N);
v<v<ll>> up(N);
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
    cin >> n >> m >> q;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        inv[a[i]] = i;
    }
    ll L = (ll)(log2(n) + 1);
    for (ll i = 0; i <= L; i++)
        up[0].pb(0);
    for (ll i = 1; i <= m; i++)
    {
        cin >> b[i];
        last[b[i]] = i;
        par[i] = last[a[(inv[b[i]] - 1 + n) % n]];
        up[i].pb(par[i]);
        for (ll j = 1; j <= L; j++)
            up[i].pb(up[up[i][j - 1]][j - 1]);
        ll temp = n - 1, temp1 = i, cnt = 0;
        while (temp > 0)
        {
            if (temp % 2 == 1)
                temp1 = up[temp1][cnt];
            cnt++;
            temp /= 2;
        }
        // cout << temp1 << " ";
        rt[i] = max(rt[i - 1], temp1);
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        if (rt[r] >= l)
            cout << '1';
        else
            cout << '0';
    }
    cout << "\n";
}