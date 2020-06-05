#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define inp_push(no, v) \
    ll no;              \
    cin >> no;          \
    v.push_back(no);
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 500005
#define mod 1000000007
#define INF INT_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

v<ll> fact(N);

long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
        // cout << x << " " << mod << "\n";
        x = (x * x) % m;
        y /= 2;
    }
    return res;
}

void init_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll C(ll n, ll r)
{
    if (n < r)
        return 0;
    ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
    temp *= powmod(fact[n - r], mod - 2, mod);
    temp %= mod;
    return temp;
}

/////////////////////////////////////START CODE HERE////////////////////////////////////////////

ll n, m;
v<v<ll>> adj(N);
v<pair<ll, ll>> a(N);
v<ll> b(N);
v<ll> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    ll f = 1;
    for (ll i = 1; i <= n; i++)
    {
        ll u = a[i].se, top = a[i].fi, val = 1;
        v<ll> vals;
        for (auto x : adj[u])
        {
            if (b[x])
                vals.pb(b[x]);
        }
        sort(vals.begin(), vals.end());
        for (ll i = 0; i < vals.size(); i++)
        {
            if (vals[i] == val)
                val++;
        }
        if (val == top)
            b[u] = val, ans.pb(u);
        else
        {
            f = 0;
            break;
        }
    }
    if (f == 0)
    {
        cout << -1 << "\n";
        return 0;
    }
    for (ll i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
}