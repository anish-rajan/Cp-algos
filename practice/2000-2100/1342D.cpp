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
ll n, k;
v<ll> a(N), c(N);
set<pair<ll, ll>> szs;
v<v<ll>> ans(N);
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
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
    {
        ll val;
        cin >> val;
        a[val]++;
    }
    for (ll i = 1; i <= k; i++)
    {
        cin >> c[i];
    }
    ll sz = 0;
    for (ll i = k; i >= 1; i--)
    {
        if (a[i] > 0)
        {
            v<pair<set<pair<ll, ll>>::iterator, pair<ll, ll>>> temp1;
            for (auto itr = szs.begin(); itr != szs.end() && a[i] > 0; itr++)
            {
                if ((*itr).fi >= c[i])
                    break;
                ll temp = (*itr).se;
                ll p = ans[temp].size();
                while (p < c[i] && a[i] > 0)
                {
                    ans[temp].pb(i);
                    a[i]--;
                    p++;
                }
                temp1.pb(mp(itr, mp(p, temp)));
            }
            for (ll i = 0; i < temp1.size(); i++)
            {
                szs.erase(temp1[i].fi);
                szs.insert(temp1[i].se);
            }
            while (a[i] > 0)
            {
                sz++;
                ll j;
                // cout << i << " " << sz << "\n";
                for (j = 1; j <= c[i] && a[i] > 0; j++)
                {
                    ans[sz].pb(i);
                    a[i]--;
                    // cout << ans[sz].back() << " ";
                }
                szs.insert(mp(j - 1, sz));
            }
        }
        // cout << "\n";
    }
    cout << sz << "\n";
    for (ll i = 1; i <= sz; i++)
    {
        cout << ans[i].size() << " ";
        for (ll j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}