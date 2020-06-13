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
#define INF INT64_MAX

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

ll n, w, h;
v<v<ll>> s(N);
v<ll> g(N), p(N), t(N);
v<ll> ansx(N), ansy(N);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    ll off = 1e5 + 5;
    cin >> n >> w >> h;
    for (ll i = 1; i <= n; i++)
    {
        cin >> g[i] >> p[i] >> t[i];
        s[p[i] - t[i] + off].pb(i);
    }
    for (ll i = 0; i < N; i++)
    {
        v<ll> x, y;
        for (auto j : s[i])
            (g[j] == 1 ? x.pb(p[j]) : y.pb(p[j]));
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        sort(s[i].begin(), s[i].end(), [](ll a, ll b) {
            if (g[a] != g[b])
                return g[a] == 2;
            else
                return g[a] == 2 ? p[a] > p[b] : p[a] < p[b];
        });
        for (ll j = 0; j < x.size(); j++)
            ansx[s[i][j]] = x[j], ansy[s[i][j]] = h;
        for (ll j = 0; j < y.size(); j++)
            ansx[s[i][x.size() + j]] = w, ansy[s[i][x.size() + j]] = y[y.size() - j - 1];
    }
    for (ll i = 1; i <= n; i++)
        cout << ansx[i] << " " << ansy[i] << "\n";
}