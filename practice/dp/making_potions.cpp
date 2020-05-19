#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll x, s;
    cin >> x >> s;
    vector<ll> a(m), b(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vector<ll> c(k), d(k);
    for (ll i = 0; i < k; i++)
    {
        cin >> c[i];
    }
    for (ll i = 0; i < k; i++)
    {
        cin >> d[i];
    }
    ll ans = x * n;
    for (ll i = 0; i < m; i++)
    {
        if (b[i] <= s)
        {
            ans = min(ans, a[i] * n);
        }
    }
    for (ll i = 0; i < m; i++)
    {
        if (b[i] <= s)
        {
            ll p = n;
            ll ind = upper_bound(d.begin(), d.end(), s - b[i]) - d.begin();
            ind--;
            if (ind != -1)
            {
                p -= c[ind];
                ans = min(ans, a[i] * p);
            }
            // cout << ind << " ";
        }
    }
    for (ll i = 0; i < k; i++)
    {
        if (d[i] <= s)
            ans = min(ans, (n - c[i]) * x);
    }
    cout << ans << "\n";
}