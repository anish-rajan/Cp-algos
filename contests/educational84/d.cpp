
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
#define N 31622779
#define mod 998244353
ll t;
v<v<ll>> factors(200005);
bool check(v<ll> arr, ll val, v<ll> c)
{
    for (ll i = 0; i < val; i++)
    {
        ll col = c[arr[i]];
        ll f = 0;
        for (ll j = i; j < arr.size(); j += val)
        {
            if (col != c[arr[j]])
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
            return true;
    }
    return false;
}

ll comp(ll ind, v<ll> a, v<ll> c, ll n, v<ll> &visited)
{
    ll ans = n;

    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (ll i = 1; i < factors.size(); i++)
    {
        for (ll j = i; j < factors.size(); j += i)
        {
            factors[j].pb(i);
        }
    }
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        v<ll> a(n + 1), c(n + 1), visited(n + 1);
        ll ans = n + 1;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 1; i <= n; i++)
        {
            cin >> c[i];
        }
        for (ll i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                ll ind1 = i;
                v<ll> arr;
                visited[ind1] = 1;
                arr.pb(ind1);
                ind1 = a[ind1];
                while (!visited[ind1])
                {
                    visited[ind1] = 1;
                    arr.pb(ind1);
                    ind1 = a[ind1];
                }
                ll m = arr.size();
                for (ll i = 0; i < factors[m].size(); i++)
                {
                    bool pos = check(arr, factors[m][i], c);
                    if (pos)
                        ans = min(ans, factors[m][i]);
                }
            }
        }
        cout << ans << "\n";
    }
}