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
#define N 200005
#define mod 998244353
ll n, m;
v<ll> p(N), p1(N), s1(N);
v<pair<ll, ll>> s(N);
map<ll, v<ll>> comp;
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
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> p[i];
        comp[p[i]].pb(i);
    }
    for (ll i = 1; i <= m; i++)
        cin >> s[i].fi, s[i].se = i;
    sort(s.begin() + 1, s.begin() + m + 1);
    ll L = log2(s[m].fi) + 2;
    ll c = 0, u = 0;
    for (ll i = 0; i <= L; i++)
    {
        ll div = 2;
        if (i == 0)
            div = 1;
        for (ll j = 1; j <= m; j++)
        {
            s[j].fi = s[j].fi / div + s[j].fi % div;
            if (comp.find(s[j].fi) != comp.end())
            {
                // cout << j << " " << p[comp[s[j]][0]] << "\n";
                // cout << s[j] << " " << comp[s[j]].back() << "\n";
                p1[comp[s[j].fi].back()] = s[j].se;
                // cout << s[j] << " " << comp[s[j]].back() << "\n";
                comp[s[j].fi].pop_back();
                if (comp[s[j].fi].size() == 0)
                    comp.erase(s[j].fi);
                s[j].fi = 0;
                s1[s[j].se] = i;
                c++, u += i;
            }
        }
    }
    cout << c << " " << u << "\n";
    for (ll i = 1; i <= m; i++)
        cout << s1[i] << " ";
    cout << "\n";
    for (ll i = 1; i <= n; i++)
        cout << p1[i] << " ";
    cout << "\n";
}